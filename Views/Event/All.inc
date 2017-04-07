<?php
// Model available in $this->model variable.
$Model = $this->Model;
//(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
if(!\Context\Utils::IsLoggedIn()) {
  print "<h3> Please log in! </h3>";
  goto eof;
}
?>
<div class="mdl-grid">
  <div class="mdl-cell mdl-cell--4-col  mdl-cell--middle">
    <label for="count"> Total count of events: <?php print count($Model); ?></label>
  </div>
  <div class="mdl-cell mdl-cell--8-col  mdl-cell--middle"></div>

  <?php foreach ($Model as $event) : ?>
    <div class="mdl-cell mdl-cell--8-col  mdl-cell--middle">
      <div class="demo-card-wide mdl-card mdl-shadow--2dp">
        <div class="mdl-card__title">
          <h2 class="mdl-card__title-text">Planned event on <?php print date('d/m/Y',$event->Date); ?> </h2>
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
          <a href="/Event/Delete?id=<?php print $event->Id ?>">
          <button class="mdl-button mdl-button--icon mdl-js-button mdl-js-ripple-effect" onclick="location.href='/Event/Delete/<?php $event->Id ?>';">
            <i class="material-icons">close</i>
          </button>
          </a>
        </div>
      </div>
    </div>
  <?php endforeach; ?>

</div>
<?php eof: ?>