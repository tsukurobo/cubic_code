// Generated by gencpp from file pwm/pwm.msg
// DO NOT EDIT!


#ifndef PWM_MESSAGE_PWM_H
#define PWM_MESSAGE_PWM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pwm
{
template <class ContainerAllocator>
struct pwm_
{
  typedef pwm_<ContainerAllocator> Type;

  pwm_()
    : on_off(0)
    , freq(0)
    , duty(0)  {
    }
  pwm_(const ContainerAllocator& _alloc)
    : on_off(0)
    , freq(0)
    , duty(0)  {
  (void)_alloc;
    }



   typedef int8_t _on_off_type;
  _on_off_type on_off;

   typedef int8_t _freq_type;
  _freq_type freq;

   typedef int8_t _duty_type;
  _duty_type duty;





  typedef boost::shared_ptr< ::pwm::pwm_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pwm::pwm_<ContainerAllocator> const> ConstPtr;

}; // struct pwm_

typedef ::pwm::pwm_<std::allocator<void> > pwm;

typedef boost::shared_ptr< ::pwm::pwm > pwmPtr;
typedef boost::shared_ptr< ::pwm::pwm const> pwmConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pwm::pwm_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pwm::pwm_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pwm::pwm_<ContainerAllocator1> & lhs, const ::pwm::pwm_<ContainerAllocator2> & rhs)
{
  return lhs.on_off == rhs.on_off &&
    lhs.freq == rhs.freq &&
    lhs.duty == rhs.duty;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pwm::pwm_<ContainerAllocator1> & lhs, const ::pwm::pwm_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pwm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::pwm::pwm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pwm::pwm_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pwm::pwm_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pwm::pwm_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pwm::pwm_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pwm::pwm_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pwm::pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "20babff89d56b350c03c58fd594a9cef";
  }

  static const char* value(const ::pwm::pwm_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x20babff89d56b350ULL;
  static const uint64_t static_value2 = 0xc03c58fd594a9cefULL;
};

template<class ContainerAllocator>
struct DataType< ::pwm::pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pwm/pwm";
  }

  static const char* value(const ::pwm::pwm_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pwm::pwm_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 on_off\n"
"int8 freq\n"
"int8 duty\n"
;
  }

  static const char* value(const ::pwm::pwm_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pwm::pwm_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.on_off);
      stream.next(m.freq);
      stream.next(m.duty);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pwm_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pwm::pwm_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pwm::pwm_<ContainerAllocator>& v)
  {
    s << indent << "on_off: ";
    Printer<int8_t>::stream(s, indent + "  ", v.on_off);
    s << indent << "freq: ";
    Printer<int8_t>::stream(s, indent + "  ", v.freq);
    s << indent << "duty: ";
    Printer<int8_t>::stream(s, indent + "  ", v.duty);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PWM_MESSAGE_PWM_H