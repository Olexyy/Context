<?php
// Model available in $this->model variable.
$Model = $this->Model;
//(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
if(!\Context\Utils::IsLoggedIn()) {
  print "<h3> Please log in! </h3>";
  goto eof;
}
?>

<form class="add-form" action="/Event/Add" method="post">
  <?php 
  HTML::mdlGrid();
    HTML::mdlCell(8);
      HTML::h3("Add event");
    HTML::mdlClose();
    HTML::mdlCell(4); HTML::mdlClose();
    HTML::mdlCell(4);
      HTML::p("Total count of events:");
    HTML::mdlClose();
    HTML::mdlCell(4, count($Model)); HTML::mdlClose();
    HTML::mdlCell(4); HTML::mdlClose(); ?>
    <div class="mdl-cell mdl-cell--4-col ">
      <?php HTML::labelFor('date', 'Input date of event:') ?>
    </div>
    <div class="mdl-cell mdl-cell--4-col ">
      <?php HTML::input('date', 'date') ?>
    </div>
    <div class="mdl-cell mdl-cell--4-col "></div>
    <div class="mdl-cell mdl-cell--4-col ">
      <label for="description"> Input description of event: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <textarea id="description" name="description" cols="17" rows="5"> </textarea>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <input class="mdl-button mdl-js-button text-white" name="add_button" value="Add event" type="submit">
    </div>
  <?php HTML::mdlClose() ?>
</form>

<?php eof: ?>