$(document).ready(function() {
  if ($('#about').length) {
    $('#nav-about').addClass('active');
  }
  if ($('#people').length) {
    $('#nav-people').addClass('active');
  }
  if ($('#projects').length) {
    $('#nav-projects').addClass('active');
  }
  if ($('#publications').length) {
    $('#nav-publications').addClass('active');
  }
  if ($('#alumni').length) {
    $('#nav-alumni').addClass('active');
  }
  if ($('#courses').length) {
    $('#nav-courses').addClass('active');
  }

  // Rudimentary hack at DBLP search
  if (window.location.pathname === "/publications") {
    loadPubs();
  }
});

function loadPubsError() {
  $("#publications").html("Error loading publications! Leave a note with <a href='mailto:dbgroup@umich.edu'>dbgroup@umich.edu</a>.");
}

function loadPubs() {
  $("#publications").html("<p>Loading publications...</p>");

  // CONFIGURE these
  var maxResultsCount = 200;

  $.ajax({
    type: 'GET',
    dataType: 'jsonp',
    callback: 'callback',
    url: 'http://dblp.org/search/publ/api',
    data: {
      // Can find these on dblp.org/search
      q: ':author:Barzan_Mozafari:|:author:Michael_J._Cafarella:|:author:H._V._Jagadish:',
      format: 'jsonp',
      h: maxResultsCount
    }, success: function (data) {
      if (data && 'result' in data && 'hits' in data.result && 'hit' in data.result.hits) {
        var pubsByYear = sortPubsByYear(data.result.hits.hit);
        renderPubs(pubsByYear);
      } else {
        loadPubsError();
      }
    }, error: function () {
      loadPubsError();
    }
  });
}

function sortPubsByYear(hits) {
  var pubsByYear = {}
  for (var hit of hits) {
    var year = hit.info.year;
    var url = hit.info.url;
    var title = hit.info.title;
    if (hit.info.authors.author.constructor === Array) {
      var authors = hit.info.authors.author.join(', ');
    } else {
      var authors = hit.info.authors.author;
    }
    // Replace all "0001" disambiguations for authors
    authors = authors.replace(/ [0-9]+/g, '');


    var venue = hit.info.venue;
    if (!venue.endsWith('.')) {
      venue += '.';
    }

    if (!(year in pubsByYear)) {
      pubsByYear[year] = [];
    }
    pubsByYear[year].push({
      url: url,
      title: title,
      authors: authors,
      venue: venue
    });
  }
  return pubsByYear;
}

function renderPubs(pubsByYear) {
  $('#publications').html('');

  // get years in sorted order
  var years = Object.keys(pubsByYear);
  years.sort().reverse();

  for (var year of years) {
    // sort by year, add h2
    $('#publications').append('<h2>' + year + '</h2>');

    var pubsList = pubsByYear[year];

    var htmlString = '<ul>';
    for (var pub of pubsList) {
      // add individual publication per year
      htmlString += '<li><b>';
      if ("url" in pub) {
        htmlString += '<a href=' + pub.url + '>' + pub.title + '</a>';
      } else {
        htmlString += pub.title;
      }

      htmlString += '</b> ';
      htmlString += pub.authors + '. ';
      htmlString += '<i>' + pub.venue + '</i></li>'
    }
    htmlString += '</ul>';
    $('#publications').append(htmlString);
  }
}
