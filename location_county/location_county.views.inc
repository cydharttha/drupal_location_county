<?php

/**
 * @file
 * Views 3 support for Location county.
 */

/**
 * Implements hook_views_data().
 */
function location_county_views_data() {
  // ----------------------------------------------------------------
  // location_county table -- basic table information.

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.

  $data['location_county']['table']['group'] = t('Location');

  // Join location_county to all the tables that would be useful
  $data['location_county']['table']['join'] = array(
    // location_county links to location via lid.
    'location' => array(
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_county links to node through location_instance via lid.
    'node' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_county links to node_revision through location_instance via lid.
    'node_revision' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // location_county links to users through location_instance via lid.
    'users' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
  );

  // ----------------------------------------------------------------
  // location_county table -- fields

  $data['location_county']['county'] = array(
    'title' => t('County'),
    'help' => t('The county of the selected location.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'empty field name' => t('None'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
  );

  return $data;
}
