<?php
// Model available in $this->model variable.
$Model = $this->Model;
$Organizer = $Model[Organizer::Key];
//(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
?>
<form class="add-form" action="/Home/Add" method="post">
  <div class="mdl-grid">
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
      <label for="count"> Total count of events: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
      <div id="count"> <?php print $Organizer->Count(); ?> </div>
    </div>
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
      <label for="date"> Input date of event: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
      <input id="date" type="date" name="date"/>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
      <label for="description"> Input description of event: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <textarea id="description" name="description" cols="17" rows="5"> </textarea>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <input class="mdl-button mdl-js-button text-white" name="add_button" value="Add event" type="submit">
    </div>
  </div>
</form>
