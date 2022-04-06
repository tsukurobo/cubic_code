; Auto-generated. Do not edit!


(cl:in-package pwm-msg)


;//! \htmlinclude pwm.msg.html

(cl:defclass <pwm> (roslisp-msg-protocol:ros-message)
  ((dire
    :reader dire
    :initarg :dire
    :type cl:fixnum
    :initform 0)
   (duty
    :reader duty
    :initarg :duty
    :type cl:fixnum
    :initform 0))
)

(cl:defclass pwm (<pwm>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pwm>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pwm)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pwm-msg:<pwm> is deprecated: use pwm-msg:pwm instead.")))

(cl:ensure-generic-function 'dire-val :lambda-list '(m))
(cl:defmethod dire-val ((m <pwm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:dire-val is deprecated.  Use pwm-msg:dire instead.")
  (dire m))

(cl:ensure-generic-function 'duty-val :lambda-list '(m))
(cl:defmethod duty-val ((m <pwm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:duty-val is deprecated.  Use pwm-msg:duty instead.")
  (duty m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pwm>) ostream)
  "Serializes a message object of type '<pwm>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dire)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'duty)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pwm>) istream)
  "Deserializes a message object of type '<pwm>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dire)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'duty)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pwm>)))
  "Returns string type for a message object of type '<pwm>"
  "pwm/pwm")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pwm)))
  "Returns string type for a message object of type 'pwm"
  "pwm/pwm")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pwm>)))
  "Returns md5sum for a message object of type '<pwm>"
  "dfc315b3736129b536317ba30fa832a1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pwm)))
  "Returns md5sum for a message object of type 'pwm"
  "dfc315b3736129b536317ba30fa832a1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pwm>)))
  "Returns full string definition for message of type '<pwm>"
  (cl:format cl:nil "uint8 dire~%uint8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pwm)))
  "Returns full string definition for message of type 'pwm"
  (cl:format cl:nil "uint8 dire~%uint8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pwm>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pwm>))
  "Converts a ROS message object to a list"
  (cl:list 'pwm
    (cl:cons ':dire (dire msg))
    (cl:cons ':duty (duty msg))
))
