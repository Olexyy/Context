<html>
    <head>
        <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Roboto:300,400,500,700" type="text/css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="https://code.getmdl.io/1.3.0/material.indigo-deep_purple.min.css" />
        <link rel="stylesheet" href="/Static/styles.css" />
        <script defer src="https://code.getmdl.io/1.3.0/material.min.js"></script>
    </head>
    <body>
        <!-- Uses a transparent header that draws on top of the layout's background -->
        <div class="demo-layout-transparent mdl-layout mdl-js-layout">
            <header class="mdl-layout__header mdl-layout__header--transparent">
                <div class="mdl-layout__header-row">
                    <!-- Title -->
                    <span class="mdl-layout-title text-muted"><h3>Organizer</h3></span>
                    <!-- Add spacer, to align navigation to the right -->
                    <div class="mdl-layout-spacer"></div>
                    <!-- Textfield with Floating Label -->
                    <?php if(!\Context\Utils::IsLoggedIn()): ?>
                        <form action="/User/Login" method="post">
                            <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                                <input class="mdl-textfield__input" name="login" type="text" id="login">
                                <label class="mdl-textfield__label" for="login">Login</label>
                            </div>
                            <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                                <input class="mdl-textfield__input" name="password" type="text" id="password">
                                <label class="mdl-textfield__label" for="password">Password</label>
                            </div>
                            <input type="submit" value="Login" name="Login" class="text-white mdl-button mdl-js-button">
                            <a href="/User/SignUpPage" class="text-white"> Sign up </a>
                        </form>
                    <?php else: ?>
                        <?php $user = \Context\Utils::GetUser(); ?>
                        <h1 class="text-white"> Welcome <?php echo $user->Name; ?> </h1>
                        <form action="/User/Logout" method="post">
                            <input type="hidden" value="<?php echo $user->Id; ?>" name="user">
                            <input type="submit" value="Logout" name="Logout" class="text-white mdl-button mdl-js-button">
                        </form>
                    <?php endif; ?>
                </div>
                <div class="mdl-layout__header-row">
                    <!-- Add spacer, to align navigation to the right -->
                    <div class="mdl-layout-spacer"></div>
                    <!-- Navigation -->
                    <nav class="mdl-navigation">
                        <a class="mdl-navigation__link" href="/Home/Index">Home</a>
                        <a class="mdl-navigation__link" href="/Event/AddPage">Add event</a>
                        <a class="mdl-navigation__link" href="/Event/All">All events</a>
                        <?php if(\Context\Utils::IsLoggedIn()): ?>
                            <a class="mdl-navigation__link" href="/User/Index">Users</a>
                        <?php endif; ?>
                    </nav>
                </div>
            </header>
            <div class="mdl-layout__drawer">
                <span class="mdl-layout-title">Organizer</span>
                <nav class="mdl-navigation">
                    <a class="mdl-navigation__link" href="/Home/Index">Home</a>
                    <a class="mdl-navigation__link" href="/Home/Add">Add record</a>
                    <a class="mdl-navigation__link" href="/Home/View">View all</a>
                </nav>
            </div>
            <main class="mdl-layout__content render-content text-white">
               <?php $this->RenderView() ?>
            </main>
        </div>
    </body>
</html>