
(cl:in-package :asdf)

(defsystem "rvc_utils-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ROCCurveMessage" :depends-on ("_package_ROCCurveMessage"))
    (:file "_package_ROCCurveMessage" :depends-on ("_package"))
    (:file "DataSetMessage" :depends-on ("_package_DataSetMessage"))
    (:file "_package_DataSetMessage" :depends-on ("_package"))
  ))