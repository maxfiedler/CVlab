; Auto-generated. Do not edit!


(cl:in-package rvc_utils-msg)


;//! \htmlinclude DataSetMessage.msg.html

(cl:defclass <DataSetMessage> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (dataset_name
    :reader dataset_name
    :initarg :dataset_name
    :type cl:string
    :initform "")
   (dataset_idx
    :reader dataset_idx
    :initarg :dataset_idx
    :type cl:fixnum
    :initform 0))
)

(cl:defclass DataSetMessage (<DataSetMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DataSetMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DataSetMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rvc_utils-msg:<DataSetMessage> is deprecated: use rvc_utils-msg:DataSetMessage instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <DataSetMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:header-val is deprecated.  Use rvc_utils-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'dataset_name-val :lambda-list '(m))
(cl:defmethod dataset_name-val ((m <DataSetMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:dataset_name-val is deprecated.  Use rvc_utils-msg:dataset_name instead.")
  (dataset_name m))

(cl:ensure-generic-function 'dataset_idx-val :lambda-list '(m))
(cl:defmethod dataset_idx-val ((m <DataSetMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:dataset_idx-val is deprecated.  Use rvc_utils-msg:dataset_idx instead.")
  (dataset_idx m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DataSetMessage>) ostream)
  "Serializes a message object of type '<DataSetMessage>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dataset_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dataset_name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dataset_idx)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DataSetMessage>) istream)
  "Deserializes a message object of type '<DataSetMessage>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dataset_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dataset_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dataset_idx)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DataSetMessage>)))
  "Returns string type for a message object of type '<DataSetMessage>"
  "rvc_utils/DataSetMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DataSetMessage)))
  "Returns string type for a message object of type 'DataSetMessage"
  "rvc_utils/DataSetMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DataSetMessage>)))
  "Returns md5sum for a message object of type '<DataSetMessage>"
  "59c0368b3e65867e9b2926656b1c15a9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DataSetMessage)))
  "Returns md5sum for a message object of type 'DataSetMessage"
  "59c0368b3e65867e9b2926656b1c15a9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DataSetMessage>)))
  "Returns full string definition for message of type '<DataSetMessage>"
  (cl:format cl:nil "Header header~%~%# Name of the data set, i.e. one of: graffiti, boat, bikes ~%string dataset_name~%~%# index of the image in the dataset from which the destination points originate~%uint8 dataset_idx~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DataSetMessage)))
  "Returns full string definition for message of type 'DataSetMessage"
  (cl:format cl:nil "Header header~%~%# Name of the data set, i.e. one of: graffiti, boat, bikes ~%string dataset_name~%~%# index of the image in the dataset from which the destination points originate~%uint8 dataset_idx~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DataSetMessage>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'dataset_name))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DataSetMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'DataSetMessage
    (cl:cons ':header (header msg))
    (cl:cons ':dataset_name (dataset_name msg))
    (cl:cons ':dataset_idx (dataset_idx msg))
))
