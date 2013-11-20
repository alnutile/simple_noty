<?php


/**
 * Implements hook_drush_command().
 */
function simple_noty_drush_command() {
    $items = array();

    $items['noty-libraries'] = array(
        'callback' => 'drush_noty_lib',
        'description' => dt("Download all the needed libraries"),
        'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
        'arguments' => array(
            'path' => dt("If you do not want to use the default library path")
        ),
        'aliases' => array('nl')
    );
    return $items;
}

/**
 * Thanks to https://drupal.org/node/1231378
 */
function drush_noty_lib(){
    if (!drush_shell_exec('type unzip')) {
        return drush_set_error(dt('Missing dependency: unzip. Install it before using this command.'));
    }

    $args = func_get_args();
    if ($args[0]) {
        $path = $args[0];
    }
    else {
        $path = 'sites/all/libraries';
    }

    // Create the path if it does not exist.
    if (!is_dir($path)) {
        drush_op('mkdir', $path);
        drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
    }

    // Set the directory to the download location.
    $olddir = getcwd();
    chdir($path);

    $libraries = array(
        'noty_library' => array('url' => 'https://github.com/needim/noty/archive/v2.1.2.zip', 'filename' => 'noty-2.1.2'),
    );

    foreach($libraries as $key => $value) {
        $dirname = $key;
        //Check if installed
        if(!is_dir($dirname)) {
            //Get zips
            if (!drush_shell_exec('wget ' . $libraries[$key]['url'] . ' -O file.zip')) {
                drush_shell_exec('curl ' . $libraries[$key]['url'] . ' > file.zip' );
            }
            //Unzip and 'remove zip
            if (is_file('file.zip')) {
                drush_shell_exec('unzip -qq -o file.zip');
                drush_op('unlink', 'file.zip');
                drush_shell_exec("mv {$libraries[$key]['filename']}  $key");
            }
        }

    }

}