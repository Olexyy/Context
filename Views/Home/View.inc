<?php
// Model available in $this->model variable.
$Model = $this->Model;
$Organizer = $Model[Organizer::Key];
//(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
?>
<div class="mdl-grid">
  <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
    <label for="count"> Total count of events: </label>
  </div>
  <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
    <div id="count"> <?php print $Organizer->Count(); ?> </div>
  </div>
  <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle"></div>

  <?php foreach ($Organizer->Events as $event) : ?>
    <div class="mdl-cell mdl-cell--8-col  mdl-cell--middle">
      <div class="demo-card-wide mdl-card mdl-shadow--2dp">
        <div class="mdl-card__title">
          <h2 class="mdl-card__title-text">Planned event on <?php print $event->Date; ?> </h2>
        </div>
        <div class="mdl-card__supporting-text">
          <?php print $event->Description; ?>
        </div>
        <div class="mdl-card__actions mdl-card--border">
          <a class="mdl-button mdl-button--colored mdl-js-button mdl-js-ripple-effect">
            Edit
          </a>
        </div>
        <div class="mdl-card__menu">
          <button class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect">
            <i class="material-icons">close</i>
          </button>
        </div>
      </div>
    </div>
  <?php endforeach; ?>

</div>
