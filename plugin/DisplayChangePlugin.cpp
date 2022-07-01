#include "DisplayChangePlugin.hpp"

// Gazebo include
#include <gazebo/rendering/rendering.hh>

namespace gazebo
{
static inline std::size_t unique_id = 0;

// How much materials you have
// 1 -> Is first frame
// NUMBER_OF_MATERIALS -> Is last frame
static constexpr std::size_t NUMBER_OF_MATERIALS = 103;
// Change picture (frame) every XXX ms.
// For example if you video has 30fps you need change
// picture every 1000/30 = 33ms
static constexpr std::size_t CHANGE_PICTURE_EVERY_MS = 100;

GZ_REGISTER_VISUAL_PLUGIN(DisplayChangePlugin)

DisplayChangePlugin::DisplayChangePlugin()
{

}

void DisplayChangePlugin::Load(rendering::VisualPtr a_model, sdf::ElementPtr a_sdf)
{
  m_id = unique_id++;
  m_model = a_model;
  m_elapsed = std::chrono::system_clock::now();
  this->m_updateConnection = event::Events::ConnectRender(
    boost::bind(&DisplayChangePlugin::UpdateChild, this));
  m_last_material = NUMBER_OF_MATERIALS;
}

void DisplayChangePlugin::UpdateChild()
{
  const auto timelaps = std::chrono::system_clock::now();
  // Change picture every XXX ms
  if (std::chrono::duration_cast<std::chrono::milliseconds>(timelaps - m_elapsed).count() >= CHANGE_PICTURE_EVERY_MS) {
    m_elapsed = timelaps;
    m_model->SetMaterial(nextMaterial(), false);
  }
}

std::string DisplayChangePlugin::nextMaterial()
{
  std::string materialName = "Demo/pic" + std::to_string(m_actual_material);
  ++m_actual_material;
  if (m_actual_material > m_last_material) {
    m_actual_material = 1u;
  }
  return materialName;
}

}// namespace gazebo
