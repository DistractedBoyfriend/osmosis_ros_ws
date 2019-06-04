// Auto-generated. Do not edit!

// (in-package robotnik_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ElevatorStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.state = null;
      this.position = null;
    }
    else {
      if (initObj.hasOwnProperty('state')) {
        this.state = initObj.state
      }
      else {
        this.state = '';
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ElevatorStatus
    // Serialize message field [state]
    bufferOffset = _serializer.string(obj.state, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.string(obj.position, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ElevatorStatus
    let len;
    let data = new ElevatorStatus(null);
    // Deserialize message field [state]
    data.state = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.state.length;
    length += object.position.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robotnik_msgs/ElevatorStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9becbfc724554c6c51b8c09125fe90d4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # state
    string RAISING=raising
    string LOWERING=lowering
    string IDLE=idle
    string ERROR_G_IO=error_getting_io
    string ERROR_S_IO=error_setting_io
    string ERROR_TIMEOUT=error_timeout_in_action
    # position
    string UP=up
    string DOWN=down
    string UNKNOWN=unknown
    # IDLE, RAISING, LOWERING
    string state
    # UP, DOWN, UNKNOWN
    string position
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ElevatorStatus(null);
    if (msg.state !== undefined) {
      resolved.state = msg.state;
    }
    else {
      resolved.state = ''
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = ''
    }

    return resolved;
    }
};

// Constants for message
ElevatorStatus.Constants = {
  RAISING: 'raising',
  LOWERING: 'lowering',
  IDLE: 'idle',
  ERROR_G_IO: 'error_getting_io',
  ERROR_S_IO: 'error_setting_io',
  ERROR_TIMEOUT: 'error_timeout_in_action',
  UP: 'up',
  DOWN: 'down',
  UNKNOWN: 'unknown',
}

module.exports = ElevatorStatus;
