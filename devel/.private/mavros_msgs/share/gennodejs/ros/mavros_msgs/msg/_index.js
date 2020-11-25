
"use strict";

let VFR_HUD = require('./VFR_HUD.js');
let RTKBaseline = require('./RTKBaseline.js');
let ESCStatusItem = require('./ESCStatusItem.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let Vibration = require('./Vibration.js');
let ExtendedState = require('./ExtendedState.js');
let ManualControl = require('./ManualControl.js');
let State = require('./State.js');
let RTCM = require('./RTCM.js');
let ESCInfo = require('./ESCInfo.js');
let WaypointReached = require('./WaypointReached.js');
let ActuatorControl = require('./ActuatorControl.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let LogData = require('./LogData.js');
let Waypoint = require('./Waypoint.js');
let LogEntry = require('./LogEntry.js');
let Trajectory = require('./Trajectory.js');
let WaypointList = require('./WaypointList.js');
let HilSensor = require('./HilSensor.js');
let PlayTuneV2 = require('./PlayTuneV2.js');
let Altitude = require('./Altitude.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let ESCInfoItem = require('./ESCInfoItem.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let VehicleInfo = require('./VehicleInfo.js');
let FileEntry = require('./FileEntry.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let RCOut = require('./RCOut.js');
let PositionTarget = require('./PositionTarget.js');
let ESCStatus = require('./ESCStatus.js');
let StatusText = require('./StatusText.js');
let HomePosition = require('./HomePosition.js');
let MountControl = require('./MountControl.js');
let Mavlink = require('./Mavlink.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let GPSRAW = require('./GPSRAW.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let GPSRTK = require('./GPSRTK.js');
let HilGPS = require('./HilGPS.js');
let RadioStatus = require('./RadioStatus.js');
let ParamValue = require('./ParamValue.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let RCIn = require('./RCIn.js');
let Param = require('./Param.js');
let CommandCode = require('./CommandCode.js');
let Thrust = require('./Thrust.js');
let DebugValue = require('./DebugValue.js');
let EstimatorStatus = require('./EstimatorStatus.js');
let BatteryStatus = require('./BatteryStatus.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let HilControls = require('./HilControls.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let LandingTarget = require('./LandingTarget.js');

module.exports = {
  VFR_HUD: VFR_HUD,
  RTKBaseline: RTKBaseline,
  ESCStatusItem: ESCStatusItem,
  OverrideRCIn: OverrideRCIn,
  Vibration: Vibration,
  ExtendedState: ExtendedState,
  ManualControl: ManualControl,
  State: State,
  RTCM: RTCM,
  ESCInfo: ESCInfo,
  WaypointReached: WaypointReached,
  ActuatorControl: ActuatorControl,
  AttitudeTarget: AttitudeTarget,
  LogData: LogData,
  Waypoint: Waypoint,
  LogEntry: LogEntry,
  Trajectory: Trajectory,
  WaypointList: WaypointList,
  HilSensor: HilSensor,
  PlayTuneV2: PlayTuneV2,
  Altitude: Altitude,
  WheelOdomStamped: WheelOdomStamped,
  ESCInfoItem: ESCInfoItem,
  GlobalPositionTarget: GlobalPositionTarget,
  VehicleInfo: VehicleInfo,
  FileEntry: FileEntry,
  TimesyncStatus: TimesyncStatus,
  RCOut: RCOut,
  PositionTarget: PositionTarget,
  ESCStatus: ESCStatus,
  StatusText: StatusText,
  HomePosition: HomePosition,
  MountControl: MountControl,
  Mavlink: Mavlink,
  HilStateQuaternion: HilStateQuaternion,
  GPSRAW: GPSRAW,
  CompanionProcessStatus: CompanionProcessStatus,
  GPSRTK: GPSRTK,
  HilGPS: HilGPS,
  RadioStatus: RadioStatus,
  ParamValue: ParamValue,
  ADSBVehicle: ADSBVehicle,
  RCIn: RCIn,
  Param: Param,
  CommandCode: CommandCode,
  Thrust: Thrust,
  DebugValue: DebugValue,
  EstimatorStatus: EstimatorStatus,
  BatteryStatus: BatteryStatus,
  CamIMUStamp: CamIMUStamp,
  HilActuatorControls: HilActuatorControls,
  OpticalFlowRad: OpticalFlowRad,
  HilControls: HilControls,
  OnboardComputerStatus: OnboardComputerStatus,
  LandingTarget: LandingTarget,
};
