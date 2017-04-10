<?php
// Model available in $this->model variable.
$Model = $this->Model;
?>
<form class="add-form" action="/User/SignUp" method="post">
  <div class="mdl-grid">
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <h3 class="title">Sign up: </h3>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <label for="username"> Username: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <input id="username" type="text" name="username"/>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <label for="password"> Password: </label>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle">
      <input id="password" type="password" name="password"/>
    </div>
    <div class="mdl-cell mdl-cell--4-col mdl-cell--middle"></div>
    <?php HTML::reCaptcha() ?>
    <div class="mdl-cell mdl-cell--8-col mdl-cell--middle">
      <input class="mdl-button mdl-js-button text-white" name="SignUp" value="SignUp" type="submit">
    </div>
  </div>
</form>