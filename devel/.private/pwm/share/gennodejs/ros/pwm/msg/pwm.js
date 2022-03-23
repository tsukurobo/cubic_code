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
      this.on_off = null;
      this.freq = null;
      this.duty = null;
    }
    else {
      if (initObj.hasOwnProperty('on_off')) {
        this.on_off = initObj.on_off
      }
      else {
        this.on_off = 0;
      }
      if (initObj.hasOwnProperty('freq')) {
        this.freq = initObj.freq
      }
      else {
        this.freq = 0;
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
    // Serialize message field [on_off]
    bufferOffset = _serializer.int8(obj.on_off, buffer, bufferOffset);
    // Serialize message field [freq]
    bufferOffset = _serializer.int8(obj.freq, buffer, bufferOffset);
    // Serialize message field [duty]
    bufferOffset = _serializer.int8(obj.duty, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type pwm
    let len;
    let data = new pwm(null);
    // Deserialize message field [on_off]
    data.on_off = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [freq]
    data.freq = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [duty]
    data.duty = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pwm/pwm';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '20babff89d56b350c03c58fd594a9cef';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int8 on_off
    int8 freq
    int8 duty
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new pwm(null);
    if (msg.on_off !== undefined) {
      resolved.on_off = msg.on_off;
    }
    else {
      resolved.on_off = 0
    }

    if (msg.freq !== undefined) {
      resolved.freq = msg.freq;
    }
    else {
      resolved.freq = 0
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
