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
});
