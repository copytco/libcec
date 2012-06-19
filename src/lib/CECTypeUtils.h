#pragma once
/*
 * This file is part of the libCEC(R) library.
 *
 * libCEC(R) is Copyright (C) 2011-2012 Pulse-Eight Limited.  All rights reserved.
 * libCEC(R) is an original work, containing original code.
 *
 * libCEC(R) is a trademark of Pulse-Eight Limited.
 *
 * This program is dual-licensed; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * Alternatively, you can license this library under a commercial license,
 * please contact Pulse-Eight Licensing for more information.
 *
 * For more information contact:
 * Pulse-Eight Licensing       <license@pulse-eight.com>
 *     http://www.pulse-eight.com/
 *     http://www.pulse-eight.net/
 */

#include "../../include/cectypes.h"

namespace CEC
{
  class CCECTypeUtils
  {
  public:
    /*!
     * @brief Get the device type for the given logical address.
     * @param address The address to get the type for.
     * @return The type, or CEC_DEVICE_TYPE_RESERVED if unknown.
     */
    static cec_device_type GetType(const cec_logical_address address)
    {
      switch (address)
      {
        case CECDEVICE_AUDIOSYSTEM:
          return CEC_DEVICE_TYPE_AUDIO_SYSTEM;
        case CECDEVICE_PLAYBACKDEVICE1:
        case CECDEVICE_PLAYBACKDEVICE2:
        case CECDEVICE_PLAYBACKDEVICE3:
          return CEC_DEVICE_TYPE_PLAYBACK_DEVICE;
        case CECDEVICE_RECORDINGDEVICE1:
        case CECDEVICE_RECORDINGDEVICE2:
        case CECDEVICE_RECORDINGDEVICE3:
          return CEC_DEVICE_TYPE_RECORDING_DEVICE;
        case CECDEVICE_TUNER1:
        case CECDEVICE_TUNER2:
        case CECDEVICE_TUNER3:
        case CECDEVICE_TUNER4:
          return CEC_DEVICE_TYPE_TUNER;
        case CECDEVICE_TV:
          return CEC_DEVICE_TYPE_TV;
        default:
          return CEC_DEVICE_TYPE_RESERVED;
      }
    }

    /*!
     * @brief Get the ackmask for all devices of the same type as the given logical address.
     * @param address The address to get the ackmask for.
     * @return The ackmask for this type.
     */
    static uint16_t GetMaskForType(cec_logical_address address)
    {
      return GetMaskForType(GetType(address));
    }

    /*!
     * @brief Get the ackmask for all devices of the given type.
     * @param type The type to get the ackmask for.
     * @return The ackmask for this type, or 0 of no types match.
     */
    static uint16_t GetMaskForType(const cec_device_type type)
    {
      switch (type)
      {
        case CEC_DEVICE_TYPE_AUDIO_SYSTEM:
        {
          cec_logical_addresses addr;
          addr.Clear();
          addr.Set(CECDEVICE_AUDIOSYSTEM);
          return addr.AckMask();
        }
        case CEC_DEVICE_TYPE_PLAYBACK_DEVICE:
        {
          cec_logical_addresses addr;
          addr.Clear();
          addr.Set(CECDEVICE_PLAYBACKDEVICE1);
          addr.Set(CECDEVICE_PLAYBACKDEVICE2);
          addr.Set(CECDEVICE_PLAYBACKDEVICE3);
          return addr.AckMask();
        }
        case CEC_DEVICE_TYPE_RECORDING_DEVICE:
        {
          cec_logical_addresses addr;
          addr.Clear();
          addr.Set(CECDEVICE_RECORDINGDEVICE1);
          addr.Set(CECDEVICE_RECORDINGDEVICE2);
          addr.Set(CECDEVICE_RECORDINGDEVICE3);
          return addr.AckMask();
        }
        case CEC_DEVICE_TYPE_TUNER:
        {
          cec_logical_addresses addr;
          addr.Clear();
          addr.Set(CECDEVICE_TUNER1);
          addr.Set(CECDEVICE_TUNER2);
          addr.Set(CECDEVICE_TUNER3);
          addr.Set(CECDEVICE_TUNER4);
          return addr.AckMask();
        }
        case CEC_DEVICE_TYPE_TV:
        {
          cec_logical_addresses addr;
          addr.Clear();
          addr.Set(CECDEVICE_TV);
          return addr.AckMask();
        }
        default:
          return 0;
      }
    }

    static const char *ToString(const cec_device_type type)
    {
      switch (type)
      {
      case CEC_DEVICE_TYPE_AUDIO_SYSTEM:
        return "audio system";
      case CEC_DEVICE_TYPE_PLAYBACK_DEVICE:
        return "playback device";
      case CEC_DEVICE_TYPE_RECORDING_DEVICE:
          return "recording device";
      case CEC_DEVICE_TYPE_RESERVED:
          return "reserved";
      case CEC_DEVICE_TYPE_TUNER:
          return "tuner";
      case CEC_DEVICE_TYPE_TV:
          return "TV";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_menu_state state)
    {
      switch (state)
      {
      case CEC_MENU_STATE_ACTIVATED:
        return "activated";
      case CEC_MENU_STATE_DEACTIVATED:
        return "deactivated";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_version version)
    {
      switch (version)
      {
      case CEC_VERSION_1_2:
        return "1.2";
      case CEC_VERSION_1_2A:
        return "1.2a";
      case CEC_VERSION_1_3:
        return "1.3";
      case CEC_VERSION_1_3A:
        return "1.3a";
      case CEC_VERSION_1_4:
        return "1.4";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_power_status status)
    {
      switch (status)
      {
      case CEC_POWER_STATUS_ON:
        return "on";
      case CEC_POWER_STATUS_STANDBY:
        return "standby";
      case CEC_POWER_STATUS_IN_TRANSITION_ON_TO_STANDBY:
        return "in transition from on to standby";
      case CEC_POWER_STATUS_IN_TRANSITION_STANDBY_TO_ON:
        return "in transition from standby to on";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_logical_address address)
    {
      switch(address)
      {
      case CECDEVICE_AUDIOSYSTEM:
        return "Audio";
      case CECDEVICE_BROADCAST:
        return "Broadcast";
      case CECDEVICE_FREEUSE:
        return "Free use";
      case CECDEVICE_PLAYBACKDEVICE1:
        return "Playback 1";
      case CECDEVICE_PLAYBACKDEVICE2:
        return "Playback 2";
      case CECDEVICE_PLAYBACKDEVICE3:
        return "Playback 3";
      case CECDEVICE_RECORDINGDEVICE1:
        return "Recorder 1";
      case CECDEVICE_RECORDINGDEVICE2:
        return "Recorder 2";
      case CECDEVICE_RECORDINGDEVICE3:
        return "Recorder 3";
      case CECDEVICE_RESERVED1:
        return "Reserved 1";
      case CECDEVICE_RESERVED2:
        return "Reserved 2";
      case CECDEVICE_TUNER1:
        return "Tuner 1";
      case CECDEVICE_TUNER2:
        return "Tuner 2";
      case CECDEVICE_TUNER3:
        return "Tuner 3";
      case CECDEVICE_TUNER4:
        return "Tuner 4";
      case CECDEVICE_TV:
        return "TV";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_deck_control_mode mode)
    {
      switch (mode)
      {
      case CEC_DECK_CONTROL_MODE_SKIP_FORWARD_WIND:
        return "skip forward wind";
      case CEC_DECK_CONTROL_MODE_EJECT:
        return "eject";
      case CEC_DECK_CONTROL_MODE_SKIP_REVERSE_REWIND:
        return "reverse rewind";
      case CEC_DECK_CONTROL_MODE_STOP:
        return "stop";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_deck_info status)
    {
      switch (status)
      {
      case CEC_DECK_INFO_PLAY:
        return "play";
      case CEC_DECK_INFO_RECORD:
        return "record";
      case CEC_DECK_INFO_PLAY_REVERSE:
        return "play reverse";
      case CEC_DECK_INFO_STILL:
        return "still";
      case CEC_DECK_INFO_SLOW:
        return "slow";
      case CEC_DECK_INFO_SLOW_REVERSE:
        return "slow reverse";
      case CEC_DECK_INFO_FAST_FORWARD:
        return "fast forward";
      case CEC_DECK_INFO_FAST_REVERSE:
        return "fast reverse";
      case CEC_DECK_INFO_NO_MEDIA:
        return "no media";
      case CEC_DECK_INFO_STOP:
        return "stop";
      case CEC_DECK_INFO_SKIP_FORWARD_WIND:
        return "info skip forward wind";
      case CEC_DECK_INFO_SKIP_REVERSE_REWIND:
        return "info skip reverse rewind";
      case CEC_DECK_INFO_INDEX_SEARCH_FORWARD:
        return "info index search forward";
      case CEC_DECK_INFO_INDEX_SEARCH_REVERSE:
        return "info index search reverse";
      case CEC_DECK_INFO_OTHER_STATUS:
        return "other";
      case CEC_DECK_INFO_OTHER_STATUS_LG:
        return "LG other";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_opcode opcode)
    {
      switch (opcode)
      {
      case CEC_OPCODE_ACTIVE_SOURCE:
        return "active source";
      case CEC_OPCODE_IMAGE_VIEW_ON:
        return "image view on";
      case CEC_OPCODE_TEXT_VIEW_ON:
        return "text view on";
      case CEC_OPCODE_INACTIVE_SOURCE:
        return "inactive source";
      case CEC_OPCODE_REQUEST_ACTIVE_SOURCE:
        return "request active source";
      case CEC_OPCODE_ROUTING_CHANGE:
        return "routing change";
      case CEC_OPCODE_ROUTING_INFORMATION:
        return "routing information";
      case CEC_OPCODE_SET_STREAM_PATH:
        return "set stream path";
      case CEC_OPCODE_STANDBY:
        return "standby";
      case CEC_OPCODE_RECORD_OFF:
        return "record off";
      case CEC_OPCODE_RECORD_ON:
        return "record on";
      case CEC_OPCODE_RECORD_STATUS:
        return "record status";
      case CEC_OPCODE_RECORD_TV_SCREEN:
        return "record tv screen";
      case CEC_OPCODE_CLEAR_ANALOGUE_TIMER:
        return "clear analogue timer";
      case CEC_OPCODE_CLEAR_DIGITAL_TIMER:
        return "clear digital timer";
      case CEC_OPCODE_CLEAR_EXTERNAL_TIMER:
        return "clear external timer";
      case CEC_OPCODE_SET_ANALOGUE_TIMER:
        return "set analogue timer";
      case CEC_OPCODE_SET_DIGITAL_TIMER:
        return "set digital timer";
      case CEC_OPCODE_SET_EXTERNAL_TIMER:
        return "set external timer";
      case CEC_OPCODE_SET_TIMER_PROGRAM_TITLE:
        return "set timer program title";
      case CEC_OPCODE_TIMER_CLEARED_STATUS:
        return "timer cleared status";
      case CEC_OPCODE_TIMER_STATUS:
        return "timer status";
      case CEC_OPCODE_CEC_VERSION:
        return "cec version";
      case CEC_OPCODE_GET_CEC_VERSION:
        return "get cec version";
      case CEC_OPCODE_GIVE_PHYSICAL_ADDRESS:
        return "give physical address";
      case CEC_OPCODE_GET_MENU_LANGUAGE:
        return "get menu language";
      case CEC_OPCODE_REPORT_PHYSICAL_ADDRESS:
        return "report physical address";
      case CEC_OPCODE_SET_MENU_LANGUAGE:
        return "set menu language";
      case CEC_OPCODE_DECK_CONTROL:
        return "deck control";
      case CEC_OPCODE_DECK_STATUS:
        return "deck status";
      case CEC_OPCODE_GIVE_DECK_STATUS:
        return "give deck status";
      case CEC_OPCODE_PLAY:
        return "play";
      case CEC_OPCODE_GIVE_TUNER_DEVICE_STATUS:
        return "give tuner status";
      case CEC_OPCODE_SELECT_ANALOGUE_SERVICE:
        return "select analogue service";
      case CEC_OPCODE_SELECT_DIGITAL_SERVICE:
        return "set digital service";
      case CEC_OPCODE_TUNER_DEVICE_STATUS:
        return "tuner device status";
      case CEC_OPCODE_TUNER_STEP_DECREMENT:
        return "tuner step decrement";
      case CEC_OPCODE_TUNER_STEP_INCREMENT:
        return "tuner step increment";
      case CEC_OPCODE_DEVICE_VENDOR_ID:
        return "device vendor id";
      case CEC_OPCODE_GIVE_DEVICE_VENDOR_ID:
        return "give device vendor id";
      case CEC_OPCODE_VENDOR_COMMAND:
        return "vendor command";
      case CEC_OPCODE_VENDOR_COMMAND_WITH_ID:
        return "vendor command with id";
      case CEC_OPCODE_VENDOR_REMOTE_BUTTON_DOWN:
        return "vendor remote button down";
      case CEC_OPCODE_VENDOR_REMOTE_BUTTON_UP:
        return "vendor remote button up";
      case CEC_OPCODE_SET_OSD_STRING:
        return "set osd string";
      case CEC_OPCODE_GIVE_OSD_NAME:
        return "give osd name";
      case CEC_OPCODE_SET_OSD_NAME:
        return "set osd name";
      case CEC_OPCODE_MENU_REQUEST:
        return "menu request";
      case CEC_OPCODE_MENU_STATUS:
        return "menu status";
      case CEC_OPCODE_USER_CONTROL_PRESSED:
        return "user control pressed";
      case CEC_OPCODE_USER_CONTROL_RELEASE:
        return "user control release";
      case CEC_OPCODE_GIVE_DEVICE_POWER_STATUS:
        return "give device power status";
      case CEC_OPCODE_REPORT_POWER_STATUS:
        return "report power status";
      case CEC_OPCODE_FEATURE_ABORT:
        return "feature abort";
      case CEC_OPCODE_ABORT:
        return "abort";
      case CEC_OPCODE_GIVE_AUDIO_STATUS:
        return "give audio status";
      case CEC_OPCODE_GIVE_SYSTEM_AUDIO_MODE_STATUS:
        return "give audio mode status";
      case CEC_OPCODE_REPORT_AUDIO_STATUS:
        return "report audio status";
      case CEC_OPCODE_SET_SYSTEM_AUDIO_MODE:
        return "set system audio mode";
      case CEC_OPCODE_SYSTEM_AUDIO_MODE_REQUEST:
        return "system audio mode request";
      case CEC_OPCODE_SYSTEM_AUDIO_MODE_STATUS:
        return "system audio mode status";
      case CEC_OPCODE_SET_AUDIO_RATE:
        return "set audio rate";
      case CEC_OPCODE_START_ARC:
        return "start ARC";
      case CEC_OPCODE_REPORT_ARC_STARTED:
        return "report ARC started";
      case CEC_OPCODE_REPORT_ARC_ENDED:
        return "report ARC ended";
      case CEC_OPCODE_REQUEST_ARC_START:
        return "request ARC start";
      case CEC_OPCODE_REQUEST_ARC_END:
        return "request ARC end";
      case CEC_OPCODE_END_ARC:
        return "end ARC";
      case CEC_OPCODE_CDC:
        return "CDC";
      case CEC_OPCODE_NONE:
        return "poll";
      default:
        return "UNKNOWN";
      }
    }

    static const char *ToString(const cec_system_audio_status mode)
    {
      switch(mode)
      {
      case CEC_SYSTEM_AUDIO_STATUS_ON:
        return "on";
      case CEC_SYSTEM_AUDIO_STATUS_OFF:
        return "off";
      default:
        return "unknown";
      }
    }

    static const char *ToString(const cec_audio_status UNUSED(status))
    {
      // TODO this is a mask
      return "TODO";
    }

    static const char *ToString(const cec_vendor_id vendor)
    {
      switch (vendor)
      {
      case CEC_VENDOR_SAMSUNG:
        return "Samsung";
      case CEC_VENDOR_LG:
        return "LG";
      case CEC_VENDOR_PANASONIC:
        return "Panasonic";
      case CEC_VENDOR_PIONEER:
        return "Pioneer";
      case CEC_VENDOR_ONKYO:
        return "Onkyo";
      case CEC_VENDOR_YAMAHA:
        return "Yamaha";
      case CEC_VENDOR_PHILIPS:
        return "Philips";
      case CEC_VENDOR_SONY:
        return "Sony";
      case CEC_VENDOR_TOSHIBA:
        return "Toshiba";
      default:
        return "Unknown";
      }
    }

    static const char *ToString(const cec_client_version version)
    {
      switch (version)
      {
      case CEC_CLIENT_VERSION_PRE_1_5:
        return "pre-1.5";
      case CEC_CLIENT_VERSION_1_5_0:
        return "1.5.0";
      case CEC_CLIENT_VERSION_1_5_1:
        return "1.5.1";
      case CEC_CLIENT_VERSION_1_5_2:
        return "1.5.2";
      case CEC_CLIENT_VERSION_1_5_3:
        return "1.5.3";
      case CEC_CLIENT_VERSION_1_6_0:
        return "1.6.0";
      case CEC_CLIENT_VERSION_1_6_1:
        return "1.6.1";
      case CEC_CLIENT_VERSION_1_6_2:
        return "1.6.2";
      case CEC_CLIENT_VERSION_1_6_3:
        return "1.6.3";
      case CEC_CLIENT_VERSION_1_7_0:
        return "1.7.0";
      default:
        return "Unknown";
      }
    }

    static const char *ToString(const cec_server_version version)
    {
      switch (version)
      {
      case CEC_SERVER_VERSION_PRE_1_5:
        return "pre-1.5";
      case CEC_SERVER_VERSION_1_5_0:
        return "1.5.0";
      case CEC_SERVER_VERSION_1_5_1:
        return "1.5.1";
      case CEC_SERVER_VERSION_1_5_2:
        return "1.5.2";
      case CEC_SERVER_VERSION_1_5_3:
        return "1.5.3";
      case CEC_SERVER_VERSION_1_6_0:
        return "1.6.0";
      case CEC_SERVER_VERSION_1_6_1:
        return "1.6.1";
      case CEC_SERVER_VERSION_1_6_2:
        return "1.6.2";
      case CEC_SERVER_VERSION_1_6_3:
        return "1.6.3";
      case CEC_SERVER_VERSION_1_7_0:
        return "1.7.0";
      default:
        return "Unknown";
      }
    }

    static const char *ToString(const cec_abort_reason reason)
    {
      switch(reason)
      {
      case CEC_ABORT_REASON_UNRECOGNIZED_OPCODE:
        return "unrecognised opcode";
      case CEC_ABORT_REASON_NOT_IN_CORRECT_MODE_TO_RESPOND:
        return "not in correct mode to respond";
      case CEC_ABORT_REASON_CANNOT_PROVIDE_SOURCE:
        return "cannot provide source";
      case CEC_ABORT_REASON_INVALID_OPERAND:
        return "invalid operand";
      case CEC_ABORT_REASON_REFUSED:
        return "refused";
      default:
        return "unknown";
      }
    }
  };
}
