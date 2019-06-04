; Auto-generated. Do not edit!


(cl:in-package robotnik_msgs-msg)


;//! \htmlinclude SetElevatorFeedback.msg.html

(cl:defclass <SetElevatorFeedback> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type robotnik_msgs-msg:ElevatorStatus
    :initform (cl:make-instance 'robotnik_msgs-msg:ElevatorStatus)))
)

(cl:defclass SetElevatorFeedback (<SetElevatorFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetElevatorFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetElevatorFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robotnik_msgs-msg:<SetElevatorFeedback> is deprecated: use robotnik_msgs-msg:SetElevatorFeedback instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <SetElevatorFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robotnik_msgs-msg:status-val is deprecated.  Use robotnik_msgs-msg:status instead.")
  (status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetElevatorFeedback>) ostream)
  "Serializes a message object of type '<SetElevatorFeedback>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'status) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetElevatorFeedback>) istream)
  "Deserializes a message object of type '<SetElevatorFeedback>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'status) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetElevatorFeedback>)))
  "Returns string type for a message object of type '<SetElevatorFeedback>"
  "robotnik_msgs/SetElevatorFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetElevatorFeedback)))
  "Returns string type for a message object of type 'SetElevatorFeedback"
  "robotnik_msgs/SetElevatorFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetElevatorFeedback>)))
  "Returns md5sum for a message object of type '<SetElevatorFeedback>"
  "6cf74bddd0ae535bf9cb994b66c1cba4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetElevatorFeedback)))
  "Returns md5sum for a message object of type 'SetElevatorFeedback"
  "6cf74bddd0ae535bf9cb994b66c1cba4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetElevatorFeedback>)))
  "Returns full string definition for message of type '<SetElevatorFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%ElevatorStatus status~%~%~%================================================================================~%MSG: robotnik_msgs/ElevatorStatus~%# state~%string RAISING=raising~%string LOWERING=lowering~%string IDLE=idle~%string ERROR_G_IO=error_getting_io~%string ERROR_S_IO=error_setting_io~%string ERROR_TIMEOUT=error_timeout_in_action~%# position~%string UP=up~%string DOWN=down~%string UNKNOWN=unknown~%# IDLE, RAISING, LOWERING~%string state~%# UP, DOWN, UNKNOWN~%string position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetElevatorFeedback)))
  "Returns full string definition for message of type 'SetElevatorFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%ElevatorStatus status~%~%~%================================================================================~%MSG: robotnik_msgs/ElevatorStatus~%# state~%string RAISING=raising~%string LOWERING=lowering~%string IDLE=idle~%string ERROR_G_IO=error_getting_io~%string ERROR_S_IO=error_setting_io~%string ERROR_TIMEOUT=error_timeout_in_action~%# position~%string UP=up~%string DOWN=down~%string UNKNOWN=unknown~%# IDLE, RAISING, LOWERING~%string state~%# UP, DOWN, UNKNOWN~%string position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetElevatorFeedback>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'status))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetElevatorFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'SetElevatorFeedback
    (cl:cons ':status (status msg))
))
