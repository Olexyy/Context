<?php
// Model available in $this->model variable.
$Model = $this->Model;
(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
?>
<form class="add-form mdl-grid" action="/Home/Add" method="post">
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
  <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
    <input class="mdl-button mdl-js-button text-white" value="Add event" type="submit">
  </div>
  <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
    <input class="mdl-button mdl-js-button text-white" value="View all" type="submit">
  </div>
    <input type="hidden" id="serialized" name="serialized" value=" <?php print $Model ?> " />
</form>
