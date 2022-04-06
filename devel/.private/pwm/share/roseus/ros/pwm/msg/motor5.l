;; Auto-generated. Do not edit!


(when (boundp 'pwm::motor5)
  (if (not (find-package "PWM"))
    (make-package "PWM"))
  (shadow 'motor5 (find-package "PWM")))
(unless (find-package "PWM::MOTOR5")
  (make-package "PWM::MOTOR5"))

(in-package "ROS")
;;//! \htmlinclude motor5.msg.html


(defclass pwm::motor5
  :super ros::object
  :slots (_dire _duty ))

(defmethod pwm::motor5
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

(setf (get pwm::motor5 :md5sum-) "e1014bb8e7f30732d4a3a679f6e8c576")
(setf (get pwm::motor5 :datatype-) "pwm/motor5")
(setf (get pwm::motor5 :definition-)
      "bool dire
int8 duty

")



(provide :pwm/motor5 "e1014bb8e7f30732d4a3a679f6e8c576")


