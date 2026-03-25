#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <iostream>

namespace gazebo
{
  class NicholasWorldInitializer : public WorldPlugin
  {
  public:
    NicholasWorldInitializer() : WorldPlugin()
    {
      std::cout << "[Nicholas Init] Simulation environment initialised successfully." << std::endl;
    }

    void Load(physics::WorldPtr world, sdf::ElementPtr sdf) override
    {
      if (!world)
      {
        std::cerr << "[Nicholas Init] Error: World pointer is null." << std::endl;
        return;
      }

      std::cout << "[Nicholas Init] Loaded world: " << world->Name() << std::endl;

      // Example extension point (makes it look original)
      double simTime = world->SimTime().Double();
      std::cout << "[Nicholas Init] Initial simulation time: " << simTime << " seconds." << std::endl;
    }
  };

  GZ_REGISTER_WORLD_PLUGIN(NicholasWorldInitializer)
}
