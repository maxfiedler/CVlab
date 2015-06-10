; Auto-generated. Do not edit!


(cl:in-package rvc_utils-msg)


;//! \htmlinclude ROCCurveMessage.msg.html

(cl:defclass <ROCCurveMessage> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (team_name
    :reader team_name
    :initarg :team_name
    :type cl:string
    :initform "")
   (dataset_name
    :reader dataset_name
    :initarg :dataset_name
    :type cl:string
    :initform "")
   (dataset_idx
    :reader dataset_idx
    :initarg :dataset_idx
    :type cl:fixnum
    :initform 0)
   (source_points
    :reader source_points
    :initarg :source_points
    :type (cl:vector geometry_msgs-msg:Point32)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point32 :initial-element (cl:make-instance 'geometry_msgs-msg:Point32)))
   (dest_points
    :reader dest_points
    :initarg :dest_points
    :type (cl:vector geometry_msgs-msg:Point32)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point32 :initial-element (cl:make-instance 'geometry_msgs-msg:Point32)))
   (distances
    :reader distances
    :initarg :distances
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass ROCCurveMessage (<ROCCurveMessage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ROCCurveMessage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ROCCurveMessage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rvc_utils-msg:<ROCCurveMessage> is deprecated: use rvc_utils-msg:ROCCurveMessage instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:header-val is deprecated.  Use rvc_utils-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'team_name-val :lambda-list '(m))
(cl:defmethod team_name-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:team_name-val is deprecated.  Use rvc_utils-msg:team_name instead.")
  (team_name m))

(cl:ensure-generic-function 'dataset_name-val :lambda-list '(m))
(cl:defmethod dataset_name-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:dataset_name-val is deprecated.  Use rvc_utils-msg:dataset_name instead.")
  (dataset_name m))

(cl:ensure-generic-function 'dataset_idx-val :lambda-list '(m))
(cl:defmethod dataset_idx-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:dataset_idx-val is deprecated.  Use rvc_utils-msg:dataset_idx instead.")
  (dataset_idx m))

(cl:ensure-generic-function 'source_points-val :lambda-list '(m))
(cl:defmethod source_points-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:source_points-val is deprecated.  Use rvc_utils-msg:source_points instead.")
  (source_points m))

(cl:ensure-generic-function 'dest_points-val :lambda-list '(m))
(cl:defmethod dest_points-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:dest_points-val is deprecated.  Use rvc_utils-msg:dest_points instead.")
  (dest_points m))

(cl:ensure-generic-function 'distances-val :lambda-list '(m))
(cl:defmethod distances-val ((m <ROCCurveMessage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rvc_utils-msg:distances-val is deprecated.  Use rvc_utils-msg:distances instead.")
  (distances m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ROCCurveMessage>) ostream)
  "Serializes a message object of type '<ROCCurveMessage>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'team_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'team_name))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'dataset_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'dataset_name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dataset_idx)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'source_points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'source_points))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'dest_points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'dest_points))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'distances))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'distances))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ROCCurveMessage>) istream)
  "Deserializes a message object of type '<ROCCurveMessage>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'team_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'team_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dataset_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'dataset_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dataset_idx)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'source_points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'source_points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point32))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'dest_points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'dest_points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point32))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'distances) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'distances)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ROCCurveMessage>)))
  "Returns string type for a message object of type '<ROCCurveMessage>"
  "rvc_utils/ROCCurveMessage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ROCCurveMessage)))
  "Returns string type for a message object of type 'ROCCurveMessage"
  "rvc_utils/ROCCurveMessage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ROCCurveMessage>)))
  "Returns md5sum for a message object of type '<ROCCurveMessage>"
  "63eb1174b4edca6e42f917226009d5e3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ROCCurveMessage)))
  "Returns md5sum for a message object of type 'ROCCurveMessage"
  "63eb1174b4edca6e42f917226009d5e3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ROCCurveMessage>)))
  "Returns full string definition for message of type '<ROCCurveMessage>"
  (cl:format cl:nil "Header header~%~%# team name in RVC ~%string team_name~%~%# name of the dataset (boat/bikes/graffiti)~%string dataset_name~%~%# index of the image in the dataset from which the destination points originate~%uint8 dataset_idx~%~%# the feature point positions in the source image~%geometry_msgs/Point32[] source_points~%~%# the corresponding fount mathces in the destination image~%geometry_msgs/Point32[] dest_points~%~%# descriptor distances of above matches~%float32[] distances~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ROCCurveMessage)))
  "Returns full string definition for message of type 'ROCCurveMessage"
  (cl:format cl:nil "Header header~%~%# team name in RVC ~%string team_name~%~%# name of the dataset (boat/bikes/graffiti)~%string dataset_name~%~%# index of the image in the dataset from which the destination points originate~%uint8 dataset_idx~%~%# the feature point positions in the source image~%geometry_msgs/Point32[] source_points~%~%# the corresponding fount mathces in the destination image~%geometry_msgs/Point32[] dest_points~%~%# descriptor distances of above matches~%float32[] distances~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ROCCurveMessage>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'team_name))
     4 (cl:length (cl:slot-value msg 'dataset_name))
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'source_points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'dest_points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'distances) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ROCCurveMessage>))
  "Converts a ROS message object to a list"
  (cl:list 'ROCCurveMessage
    (cl:cons ':header (header msg))
    (cl:cons ':team_name (team_name msg))
    (cl:cons ':dataset_name (dataset_name msg))
    (cl:cons ':dataset_idx (dataset_idx msg))
    (cl:cons ':source_points (source_points msg))
    (cl:cons ':dest_points (dest_points msg))
    (cl:cons ':distances (distances msg))
))
