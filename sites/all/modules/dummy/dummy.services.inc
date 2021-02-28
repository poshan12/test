<?php 

    function dummy_resource()
    {
       $api = array(
            'dummy-api' => array(
                'operations' => array(
                    'index' => array(
                        'help' => 'get dummy data of certificates',
                        'callback' => 'get_dummy',
                        'file' => array('type' =>'inc' ,'module' =>'dummy', 'name' => 'dummy.services'),
                        'access callback' => '_custom_resource_access',
                        'access arguments' => array(),
                        'access arguments append' => TRUE,
                        'args' => array(),
                        ),
                    ),
                ),
            );
     return $api;
    }

    function _custom_resource_access()
    {
        return TRUE;
    }

    function get_dummy()
    {
        $par=drupal_get_query_parameters();
        $id=$par['id'];
        $cname=$par['cname'];

        if(!empty($id) && !empty($cname))
        {
            $rs=db_query("SELECT `id`, `certificate_name`, `left_header`, `center_header`, `right_header` FROM `certificates` WHERE `id`='$id' AND `certificate_name`='$cname'")->fetchAll();
            return $rs; 
        }
        if(!empty($id))
        {
            $rs=db_query("SELECT `id`, `certificate_name`, `left_header`, `center_header`, `right_header` FROM `certificates` where `id`='$id'")->fetchAll();
            return $rs; 
        }
        else
        {
            $rs=db_query('SELECT `id`, `certificate_name`, `left_header`, `center_header`, `right_header` FROM `certificates`')->fetchAll();
            return $rs; 
        }
    }

?>