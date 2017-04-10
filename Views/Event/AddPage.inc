<?php
// Model available in $this->model variable.
$Model = $this->Model;
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
    HTML::mdlCell(4); HTML::mdlClose(); ?>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
        <input class="mdl-textfield__input" value="<?php print date('Y-m-d')?>" name="date" type="date" id="date">
        <label class="mdl-textfield__label" for="date">Input date</label>
      </div>
    </div>
    <div class="mdl-cell mdl-cell--4-col "></div>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <div class="mdl-textfield mdl-js-textfield text-white mdl-textfield--floating-label">
        <textarea class="mdl-textfield__input" name="description" type="text" width="400" rows= "3" id="description" ></textarea>
        <label class="mdl-textfield__label" for="description">Description of event</label>
      </div>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <input class="mdl-button mdl-js-button text-white" name="add_button" value="Add event" type="submit">
    </div>
  <?php HTML::mdlClose() ?>
</form>

<?php eof: ?>