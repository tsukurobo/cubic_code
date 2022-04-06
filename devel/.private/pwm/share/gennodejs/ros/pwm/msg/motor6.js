// Auto-generated. Do not edit!

// (in-package pwm.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class motor6 {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.dire = null;
      this.duty = null;
    }
    else {
      if (initObj.hasOwnProperty('dire')) {
        this.dire = initObj.dire
      }
      else {
        this.dire = false;
      }
      if (initObj.hasOwnProperty('duty')) {
        this.duty = initObj.duty
      }
      else {
        this.duty = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type motor6
    // Serialize message field [dire]
    bufferOffset = _serializer.bool(obj.dire, buffer, bufferOffset);
    // Serialize message field [duty]
    bufferOffset = _serializer.int8(obj.duty, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type motor6
    let len;
    let data = new motor6(null);
    // Deserialize message field [dire]
    data.dire = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [duty]
    data.duty = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pwm/motor6';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e1014bb8e7f30732d4a3a679f6e8c576';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool dire
    int8 duty
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new motor6(null);
    if (msg.dire !== undefined) {
      resolved.dire = msg.dire;
    }
    else {
      resolved.dire = false
    }

    if (msg.duty !== undefined) {
      resolved.duty = msg.duty;
    }
    else {
      resolved.duty = 0
    }

    return resolved;
    }
};

module.exports = motor6;
