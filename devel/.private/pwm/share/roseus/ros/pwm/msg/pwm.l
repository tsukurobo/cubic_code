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
  :slots (_on_off _freq _duty ))

(defmethod pwm::pwm
  (:init
   (&key
    ((:on_off __on_off) 0)
    ((:freq __freq) 0)
    ((:duty __duty) 0)
    )
   (send-super :init)
   (setq _on_off (round __on_off))
   (setq _freq (round __freq))
   (setq _duty (round __duty))
   self)
  (:on_off
   (&optional __on_off)
   (if __on_off (setq _on_off __on_off)) _on_off)
  (:freq
   (&optional __freq)
   (if __freq (setq _freq __freq)) _freq)
  (:duty
   (&optional __duty)
   (if __duty (setq _duty __duty)) _duty)
  (:serialization-length
   ()
   (+
    ;; int8 _on_off
    1
    ;; int8 _freq
    1
    ;; int8 _duty
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _on_off
       (write-byte _on_off s)
     ;; int8 _freq
       (write-byte _freq s)
     ;; int8 _duty
       (write-byte _duty s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _on_off
     (setq _on_off (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _on_off 127) (setq _on_off (- _on_off 256)))
   ;; int8 _freq
     (setq _freq (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _freq 127) (setq _freq (- _freq 256)))
   ;; int8 _duty
     (setq _duty (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _duty 127) (setq _duty (- _duty 256)))
   ;;
   self)
  )

(setf (get pwm::pwm :md5sum-) "20babff89d56b350c03c58fd594a9cef")
(setf (get pwm::pwm :datatype-) "pwm/pwm")
(setf (get pwm::pwm :definition-)
      "int8 on_off
int8 freq
int8 duty

")



(provide :pwm/pwm "20babff89d56b350c03c58fd594a9cef")


