<?php
// $Id: simple_contest.theme.inc,v 1.1 2010/06/28 15:42:05 4vinoth Exp $

/**
 * @file
 * Theme and template preprocessing code
 */


/**
 * Theme the simple contest node title
 */
function theme_simple_contest_node_title($node) {

  $settings = simple_contest_get_settings($node->type);
	$field_name = $settings['date_field'];
	$field = FALSE;
	
	$content_type_info = _content_type_info();
  if ($content_type_info['content types'][$node->type]) {
    foreach ($content_type_info['content types'][$node->type]['fields'] as $f) {
      if ($f['field_name'] == $field_name) {
				$field = $f;
        break;
      }
    }
  }
	$output = check_plain($node->title) ;
	//$output = "<div>" . check_plain($node->title) . "</div>";
	// TODO : theme the date field
	//$output .= "<div>" . theme('date_display_combination', $node) . "</div>";
	
	return $output;
}
/**
 * Theme the simple contest node title
 */
function theme_simple_contest_on_participant_node($node) {

	$content['contest'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contest'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
	$content['contest']['node'] = array(
		'#value' => "<h2>" . check_plain($node->title) . "</h2>" . node_show($node, TRUE, FALSE),
	);
	$output = drupal_render($content);

	return $output;
}

/**
 * Theme the simple contest results_display
 */
function theme_simple_contest_results_display($node, $results) {

	$content['contest'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contest winners'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
	$content['contest']['winners'] = array(
		'#value' => "<h2>" . check_plain('Winner(s)') . "</h2>" . $results,
	);
	$output = drupal_render($content);

	return $output;
}

