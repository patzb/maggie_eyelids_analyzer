#!/usr/bin/env python

import roslib; roslib.load_manifest('maggie_eyelids_analyzer')

import rospy
from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue

if __name__ == '__main__':
    rospy.init_node('eyelids_node_main')

    pub = rospy.Publisher('/diagnostics', DiagnosticArray)
    
    array = DiagnosticArray()
    # Right eyelid
    eye_right_stat = DiagnosticStatus(name = 'Right Eyelid', level = 0, 
                                  message = 'Connected')
    #Left eyelid
    eye_left_stat = DiagnosticStatus(name='Left Eyelid', level = 0,
                                message = 'Connected')

    array.status = [ eye_right_stat, eye_left_stat ]

    my_rate = rospy.Rate(1.0)
    while not rospy.is_shutdown():
        pub.publish(array)
        my_rate.sleep()
