; Auto-generated. Do not edit!


(cl:in-package pwm-msg)


;//! \htmlinclude pwm.msg.html

(cl:defclass <pwm> (roslisp-msg-protocol:ros-message)
  ((on_off
    :reader on_off
    :initarg :on_off
    :type cl:fixnum
    :initform 0)
   (freq
    :reader freq
    :initarg :freq
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

(cl:ensure-generic-function 'on_off-val :lambda-list '(m))
(cl:defmethod on_off-val ((m <pwm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:on_off-val is deprecated.  Use pwm-msg:on_off instead.")
  (on_off m))

(cl:ensure-generic-function 'freq-val :lambda-list '(m))
(cl:defmethod freq-val ((m <pwm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:freq-val is deprecated.  Use pwm-msg:freq instead.")
  (freq m))

(cl:ensure-generic-function 'duty-val :lambda-list '(m))
(cl:defmethod duty-val ((m <pwm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pwm-msg:duty-val is deprecated.  Use pwm-msg:duty instead.")
  (duty m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pwm>) ostream)
  "Serializes a message object of type '<pwm>"
  (cl:let* ((signed (cl:slot-value msg 'on_off)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'freq)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'duty)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pwm>) istream)
  "Deserializes a message object of type '<pwm>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'on_off) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'freq) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'duty) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
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
  "20babff89d56b350c03c58fd594a9cef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pwm)))
  "Returns md5sum for a message object of type 'pwm"
  "20babff89d56b350c03c58fd594a9cef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pwm>)))
  "Returns full string definition for message of type '<pwm>"
  (cl:format cl:nil "int8 on_off~%int8 freq~%int8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pwm)))
  "Returns full string definition for message of type 'pwm"
  (cl:format cl:nil "int8 on_off~%int8 freq~%int8 duty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pwm>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pwm>))
  "Converts a ROS message object to a list"
  (cl:list 'pwm
    (cl:cons ':on_off (on_off msg))
    (cl:cons ':freq (freq msg))
    (cl:cons ':duty (duty msg))
))
