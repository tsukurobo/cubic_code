
(cl:in-package :asdf)

(defsystem "pwm-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "pwm" :depends-on ("_package_pwm"))
    (:file "_package_pwm" :depends-on ("_package"))
  ))