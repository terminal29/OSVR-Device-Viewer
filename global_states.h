#include <osvr/ClientKit/InterfaceStateC.h>
#ifndef GLOBAL_STATES_OSVR
#define GLOBAL_STATES_OSVR
namespace global_states {
	static OSVR_AccelerationState acc_s;
	static OSVR_AnalogState alg_s;
	static OSVR_ButtonState btn_s;
	static OSVR_DirectionState dir_s;
	static OSVR_EyeTracker2DState et2d_s;
	static OSVR_EyeTracker3DState et3d_s;
	static OSVR_EyeTrackerBlinkState etb_s;
	static OSVR_ImagingState img_s;
	static OSVR_Location2DState l2d_s;
	static OSVR_NaviPositionState npos_s;
	static OSVR_NaviVelocityState nvel_s;
	static OSVR_PoseState p_s;
	static OSVR_VelocityState v_s;

	inline void reset_all() {
		acc_s = OSVR_AccelerationState();
		alg_s = OSVR_AnalogState();
		btn_s = OSVR_ButtonState();
		dir_s = OSVR_DirectionState();
		et2d_s = OSVR_EyeTracker2DState();
		et3d_s = OSVR_EyeTracker3DState();
		etb_s = OSVR_EyeTrackerBlinkState();
		img_s = OSVR_ImagingState();
		l2d_s = OSVR_Location2DState();
		npos_s = OSVR_NaviPositionState();
		nvel_s = OSVR_NaviVelocityState();
		p_s = OSVR_PoseState();
		v_s = OSVR_VelocityState();
	}

	inline void button_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_ButtonReport *report) {
		btn_s = report->state;
	}

	inline void analog_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_AnalogReport *report) {
		alg_s = report->state;
	}

	inline void acceleration_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_AccelerationReport *report) {
		acc_s = report->state;
	}

	inline void direction_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_DirectionReport *report) {
		dir_s = report->direction;
	}

	inline void eye_tracker_2d_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_EyeTracker2DReport *report) {
		et2d_s = report->state;
	}

	inline void eye_tracker_3d_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_EyeTracker3DReport *report) {
		et3d_s = report->state;
	}

	inline void eye_tracker_blink_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_EyeTrackerBlinkReport *report) {
		etb_s = report->state;
	}

	inline void imaging_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_ImagingReport *report) {
		img_s = report->state;
	}

	inline void location_2d_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_Location2DReport *report) {
		l2d_s = report->location;
	}

	inline void navi_position_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_NaviPositionReport *report) {
		npos_s = report->state;
	}

	inline void navi_velocity_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_NaviVelocityReport *report) {
		nvel_s = report->state;
	}

	inline void pose_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_PoseReport *report) {
		p_s = report->pose;
	}

	inline void velocity_callback(void * /*userdata*/, const OSVR_TimeValue * /*timestamp*/, const OSVR_VelocityReport *report) {
		v_s = report->state;
	}

}
#endif
