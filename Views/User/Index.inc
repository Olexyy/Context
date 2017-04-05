<?php
// Model available in $this->model variable.
$Model = $this->Model;

(count($this->Messages))? print 'Messages: '. implode('<br>', $this->Messages) : print '';
?>
<div class="mdl-grid">
  <div class="mdl-cell mdl-cell--2-col"></div>
  <div class="mdl-cell mdl-cell--6-col">
    <ul class='mdl-list'>
      <h3>Users</h3>
      <?php foreach ($Model as $user): ?>
        <li class="mdl-list__item mdl-list__item--three-line">
          <span class="mdl-list__item-primary-content">
            <i class="material-icons mdl-list__item-avatar">person</i>
            <span><?php echo $user->Name; ?></span>
            <span class="mdl-list__item-text-body">
              <?php echo $user->Password; ?>
            </span>
          </span>
          <span class="mdl-list__item-secondary-content">
            <a class="mdl-list__item-secondary-action" href="#"><i class="material-icons">star</i></a>
          </span>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
  <div class="mdl-cell mdl-cell--4-col"></div>
</div>