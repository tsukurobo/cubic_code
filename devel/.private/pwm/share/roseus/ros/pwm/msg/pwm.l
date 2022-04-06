;; Auto-generated. Do not edit!


(when (boundp 'pwm::pwm)
  (if (not (find-package "PWM"))
    (make-package "PWM"))
  (shadow 'pwm (find-package "PWM")))
(unless (find-package "PWM::PWM")
  (make-package "PWM::PWM"))

(in-package "ROS")
;;//! \htmlinclude pwm.msg.html


(defclass pwm::pwm
  :super ros::object
  :slots (_dire _duty ))

(defmethod pwm::pwm
  (:init
   (&key
    ((:dire __dire) 0)
    ((:duty __duty) 0)
    )
   (send-super :init)
   (setq _dire (round __dire))
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
    ;; uint8 _dire
    1
    ;; uint8 _duty
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _dire
       (write-byte _dire s)
     ;; uint8 _duty
       (write-byte _duty s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _dire
     (setq _dire (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _duty
     (setq _duty (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get pwm::pwm :md5sum-) "dfc315b3736129b536317ba30fa832a1")
(setf (get pwm::pwm :datatype-) "pwm/pwm")
(setf (get pwm::pwm :definition-)
      "uint8 dire
uint8 duty

")



(provide :pwm/pwm "dfc315b3736129b536317ba30fa832a1")


