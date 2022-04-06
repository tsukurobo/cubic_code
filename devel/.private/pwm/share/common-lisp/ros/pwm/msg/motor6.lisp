; Auto-generated. Do not edit!


(cl:in-package pwm-msg)


;//! \htmlinclude motor6.msg.html

(cl:defclass <motor6> (roslisp-msg-protocol:ros-message)
  ((dire
    :reader dire
    :initarg :dire
    :type cl:boolean
    :initform cl:nil)
   (duty
    :reader duty
    :initarg :duty
    :type cl:fixnum
    :initform 0))
)

(cl:defclass motor6 (<motor6>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motor6>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motor6)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pwm-msg:<motor6> is deprecated: use pwm-msg:motor6 instead.")))

(cl:ensure-generic-function 'dire-val :lambda-list '(m))
(cl:defmethod dire-val ((m <motor6>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:dire-val is deprecated.  Use pwm-msg:dire instead.")
  (dire m))

(cl:ensure-generic-function 'duty-val :lambda-list '(m))
(cl:defmethod duty-val ((m <motor6>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:duty-val is deprecated.  Use pwm-msg:duty instead.")
  (duty m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motor6>) ostream)
  "Serializes a message object of type '<motor6>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'dire) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'duty)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motor6>) istream)
  "Deserializes a message object of type '<motor6>"
    (cl:setf (cl:slot-value msg 'dire) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'duty) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motor6>)))
  "Returns string type for a message object of type '<motor6>"
  "pwm/motor6")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motor6)))
  "Returns string type for a message object of type 'motor6"
  "pwm/motor6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motor6>)))
  "Returns md5sum for a message object of type '<motor6>"
  "e1014bb8e7f30732d4a3a679f6e8c576")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motor6)))
  "Returns md5sum for a message object of type 'motor6"
  "e1014bb8e7f30732d4a3a679f6e8c576")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motor6>)))
  "Returns full string definition for message of type '<motor6>"
  (cl:format cl:nil "bool dire~%int8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motor6)))
  "Returns full string definition for message of type 'motor6"
  (cl:format cl:nil "bool dire~%int8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motor6>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motor6>))
  "Converts a ROS message object to a list"
  (cl:list 'motor6
    (cl:cons ':dire (dire msg))
    (cl:cons ':duty (duty msg))
))
