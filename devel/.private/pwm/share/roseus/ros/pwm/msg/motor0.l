;; Auto-generated. Do not edit!


(when (boundp 'pwm::motor0)
  (if (not (find-package "PWM"))
    (make-package "PWM"))
  (shadow 'motor0 (find-package "PWM")))
(unless (find-package "PWM::MOTOR0")
  (make-package "PWM::MOTOR0"))

(in-package "ROS")
;;//! \htmlinclude motor0.msg.html


(defclass pwm::motor0
  :super ros::object
  :slots (_dire _duty ))

(defmethod pwm::motor0
  (:init
   (&key
    ((:dire __dire) nil)
    ((:duty __duty) 0)
    )
   (send-super :init)
   (setq _dire __dire)
   (setq _duty (round __duty))
   self)
  (:dire
   (&optional __dire)
   (if __dire (setq _dire __dire)) _dire)
  (:duty
   (&optional __duty)
   (if __duty (setq _duty __duty)) _duty)
  (:serialization-length
   ()
   (+
    ;; bool _dire
    1
    ;; int8 _duty
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _dire
       (if _dire (write-byte -1 s) (write-byte 0 s))
     ;; int8 _duty
       (write-byte _duty s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _dire
     (setq _dire (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int8 _duty
     (setq _duty (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _duty 127) (setq _duty (- _duty 256)))
   ;;
   self)
  )

(setf (get pwm::motor0 :md5sum-) "e1014bb8e7f30732d4a3a679f6e8c576")
(setf (get pwm::motor0 :datatype-) "pwm/motor0")
(setf (get pwm::motor0 :definition-)
      "bool dire
int8 duty

")



(provide :pwm/motor0 "e1014bb8e7f30732d4a3a679f6e8c576")


