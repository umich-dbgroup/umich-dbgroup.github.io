import org.ncibi.task.TaskStatus;
import org.ncibi.ws.Response;
import org.ncibi.ws.client.NcibiThinkbackService;
import org.ncibi.ws.request.RequestStatus;
import org.ncibi.ws.thinkback.ThinkBackResults;


public class THINK_Back_Client {
	
	public static void main(String[] args) {
		submitThinkbackRequest();
	}
	    
	private static void submitThinkbackRequest() {
		
		NcibiThinkbackService thinkback = new NcibiThinkbackService();
		String base = "./";
		
		/**
		 * Parameters for the web service call:
		 * Gene Set Enrichment Method: {GSEA | LRPATH}
		 * THINK-Back Adjustment Method: {DS | AF }
		 * Sample file (GCT file)
		 * Class file  (Corresponding to the GCT file)
		 * Geneset matrix
		 * Chip file
		 */
		Response<String> response = thinkback.submitThinkBackRequest("GSEA", "DS", 
				base + "GSE3494.gct", base + "3494.cls", base + "keggdata.txt", base + "HG_U133A.chip");
		
		if (!response.isSuccess()) {
			return;
		}
		
		String uuid = response.getResponseValue();
		
		Response<RequestStatus<ThinkBackResults>> results = thinkback.thinkbackStatus(uuid);
		
		while (true) {
			TaskStatus taskStatus = results.getResponseValue().getTask().getStatus();
			if (taskStatus == TaskStatus.ERRORED || taskStatus == TaskStatus.CANCELED) {
				System.out.println("Unable to complete task, status: " + taskStatus);
			} else if (taskStatus != TaskStatus.DONE) {
				System.out.println("Waiting for completion, status: " + taskStatus);
				sleep(10 * 60); // Sleep 10 minutes.
			} else if (taskStatus == TaskStatus.DONE) {
				break;
			}
			results = thinkback.thinkbackStatus(uuid);
		}
	}
	
	private static void sleep(int seconds) {
		try {
			Thread.sleep(seconds * 1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
