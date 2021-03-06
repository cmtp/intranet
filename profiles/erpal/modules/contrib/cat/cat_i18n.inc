<?php

/**
 * @file Internationalization (i18n) class.
 *
 * @author Oleksiy Kalinichenko <aexchecker@gmail.com>
 */

/**
 * CAT item i18n object.
 */
class i18n_cat_item_object extends i18n_string_object_wrapper {

  /**
   * Construct
   *
   * @param string $type
   * @param object $object
   */
  public function __construct($type, $object) {
    $this->type = $type;
    $this->object = is_scalar($object) ? $this->load_object($object) : $object;
  }

  /**
   * Translation mode for object.
   *
   * @return int Constant showing translate mode.
   */
  public function get_translate_mode() {
    if (!empty($this->object->translatable)) {
  	  return I18N_MODE_TRANSLATE;
    }
    
    return I18N_MODE_NONE;
  }

  /**
   * Access to object translation.
   * This should check object properties and permissions.
   *
   * @return bool Param showing whether CAT item is translatable or not.
   */
  protected function translate_access() {
    return user_access('translate interface')
      && user_access('administer cat items')
      && $this->object->translatable;
  }

  /**
   * Get object strings for translation.
   *
   * @return mixed Translated properties.
   */
  protected function build_properties() {
    $properties = parent::build_properties();
    list ($string_type, $object_id) = $this->get_string_context();
    if (!empty($this->object->cat_tabs)) {
      foreach ($this->object->cat_tabs as $key => $title) {
        $properties[$this->get_textgroup()][$string_type][$object_id]['titles:' . $key] = array(
          'string' => $title,
          'title' => t('Title: @title (path: @path)', array(
            '@title' => $this->object->cat_tabs[$key]['title'],
            '@path' => $this->object->cat_tabs[$key]['path_original']
          ))
        );
      }
    }

    return $properties;
  }

}

