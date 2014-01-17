<?php

/**
 * @file
 * Contains the light display plugin.
 */

/**
 * The plugin that handles a light display.
 *
 * @ingroup views_display_plugins
 */
class views_light_display_light_display extends views_plugin_display {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * The display block handler returns the structure necessary for a block.
   */
  function execute() {
    return $this->view->render($this->display->id);
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'exposed_form_options':
        $this->view->init_handlers();
        if (!$this->uses_exposed() && parent::uses_exposed()) {
          $form['exposed_form_options']['warning'] = array(
            '#weight' => -10,
            '#markup' => '<div class="messages warning">' . t('Exposed filters in light displays require "Use AJAX" to be set to work correctly.') . '</div>',
          );
        }
    }
  }

  /**
   * Perform any necessary changes to the form values prior to storage.
   * There is no need for this function to actually store the data.
   */
  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
  }

  /**
   * Block views use exposed widgets only if AJAX is set.
   */
  function uses_exposed() {
    if ($this->use_ajax()) {
      return parent::uses_exposed();
    }
    return FALSE;
  }
}
