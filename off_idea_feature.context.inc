<?php
/**
 * @file
 * off_idea_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function off_idea_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ideas_group_block';
  $context->description = 'Show ideas block on groups/group content.';
  $context->tag = 'idea feature';
  $context->conditions = array(
    'context_og_condition_group_type' => array(
      'values' => array(
        '_any_' => '_any_',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-idea_list-group_block' => array(
          'module' => 'views',
          'delta' => 'idea_list-group_block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show ideas block on groups/group content.');
  t('idea feature');
  $export['ideas_group_block'] = $context;

  return $export;
}
