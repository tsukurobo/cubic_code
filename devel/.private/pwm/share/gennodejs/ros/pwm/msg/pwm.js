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

class pwm {
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
        this.dire = 0;
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
    // Serializes a message object of type pwm
    // Serialize message field [dire]
    bufferOffset = _serializer.uint8(obj.dire, buffer, bufferOffset);
    // Serialize message field [duty]
    bufferOffset = _serializer.uint8(obj.duty, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pwm
    let len;
    let data = new pwm(null);
    // Deserialize message field [dire]
    data.dire = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [duty]
    data.duty = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pwm/pwm';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dfc315b3736129b536317ba30fa832a1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 dire
    uint8 duty
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pwm(null);
    if (msg.dire !== undefined) {
      resolved.dire = msg.dire;
    }
    else {
      resolved.dire = 0
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

module.exports = pwm;
