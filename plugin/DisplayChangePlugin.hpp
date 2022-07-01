#ifndef DISPLAY_CHANGE_DISPLAYCHANGEPLUGIN_HPP_
#define DISPLAY_CHANGE_DISPLAYCHANGEPLUGIN_HPP_

#include <gazebo/common/Plugin.hh>
#include <chrono>
#include <string>

namespace gazebo
{
class DisplayChangePlugin : public VisualPlugin
{
public:
  DisplayChangePlugin();
  virtual void Load(rendering::VisualPtr a_model, sdf::ElementPtr a_sdf) override;
  virtual void UpdateChild();

private:
  std::string nextMaterial();

  rendering::VisualPtr m_model;
  event::ConnectionPtr m_updateConnection;
  std::size_t m_id;
  std::chrono::_V2::system_clock::time_point m_elapsed;
  std::size_t m_actual_material = 1u;
  std::size_t m_last_material = 1u;
};
}
#endif // DISPLAY_CHANGE_DISPLAYCHANGEPLUGIN_HPP_
