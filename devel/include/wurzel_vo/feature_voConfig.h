//#line 2 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the wurzel_vo package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __wurzel_vo__FEATURE_VOCONFIG_H__
#define __wurzel_vo__FEATURE_VOCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace wurzel_vo
{
  class feature_voConfigStatics;
  
  class feature_voConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(feature_voConfig &config, const feature_voConfig &max, const feature_voConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const feature_voConfig &config1, const feature_voConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, feature_voConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const feature_voConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, feature_voConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const feature_voConfig &config) const = 0;
      virtual void getValue(const feature_voConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T feature_voConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (feature_voConfig::* field);

      virtual void clamp(feature_voConfig &config, const feature_voConfig &max, const feature_voConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const feature_voConfig &config1, const feature_voConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, feature_voConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const feature_voConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, feature_voConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const feature_voConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const feature_voConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, feature_voConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); i++)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;
        
        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }
      
      virtual void updateParams(boost::any &cfg, feature_voConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++) 
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); i++)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<feature_voConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(feature_voConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = params.begin(); i != params.end(); i++)
      {
        boost::any val;
        (*i)->getValue(config, val);

        if("max_disparity"==(*i)->name){max_disparity = boost::any_cast<int>(val);}
        if("min_disparity"==(*i)->name){min_disparity = boost::any_cast<int>(val);}
        if("max_move_dist"==(*i)->name){max_move_dist = boost::any_cast<int>(val);}
        if("max_3d_dist"==(*i)->name){max_3d_dist = boost::any_cast<double>(val);}
        if("numOfIter"==(*i)->name){numOfIter = boost::any_cast<int>(val);}
        if("subsetSize"==(*i)->name){subsetSize = boost::any_cast<int>(val);}
        if("inlier_dist_threshold"==(*i)->name){inlier_dist_threshold = boost::any_cast<double>(val);}
        if("publish_pcl"==(*i)->name){publish_pcl = boost::any_cast<bool>(val);}
        if("publish_marker"==(*i)->name){publish_marker = boost::any_cast<bool>(val);}
        if("publish_temporalMatchImg"==(*i)->name){publish_temporalMatchImg = boost::any_cast<bool>(val);}
        if("publish_stereoMatchImg"==(*i)->name){publish_stereoMatchImg = boost::any_cast<bool>(val);}
      }
    }

    int max_disparity;
int min_disparity;
int max_move_dist;
double max_3d_dist;
int numOfIter;
int subsetSize;
double inlier_dist_threshold;
bool publish_pcl;
bool publish_marker;
bool publish_temporalMatchImg;
bool publish_stereoMatchImg;

    bool state;
    std::string name;

    
}groups;



//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int max_disparity;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int min_disparity;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int max_move_dist;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double max_3d_dist;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int numOfIter;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int subsetSize;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double inlier_dist_threshold;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_pcl;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_marker;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_temporalMatchImg;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_stereoMatchImg;
//#line 255 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("feature_voConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const feature_voConfig &__max__ = __getMax__();
      const feature_voConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const feature_voConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const feature_voConfig &__getDefault__();
    static const feature_voConfig &__getMax__();
    static const feature_voConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const feature_voConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void feature_voConfig::ParamDescription<std::string>::clamp(feature_voConfig &config, const feature_voConfig &max, const feature_voConfig &min) const
  {
    return;
  }

  class feature_voConfigStatics
  {
    friend class feature_voConfig;
    
    feature_voConfigStatics()
    {
feature_voConfig::GroupDescription<feature_voConfig::DEFAULT, feature_voConfig> Default("Default", "", 0, 0, true, &feature_voConfig::groups);
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_disparity = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_disparity = 500;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_disparity = 300;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("max_disparity", "int", 0, "", "", &feature_voConfig::max_disparity)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("max_disparity", "int", 0, "", "", &feature_voConfig::max_disparity)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.min_disparity = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.min_disparity = 30;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.min_disparity = 6;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("min_disparity", "int", 0, "", "", &feature_voConfig::min_disparity)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("min_disparity", "int", 0, "", "", &feature_voConfig::min_disparity)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_move_dist = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_move_dist = 500;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_move_dist = 300;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("max_move_dist", "int", 0, "", "", &feature_voConfig::max_move_dist)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("max_move_dist", "int", 0, "", "", &feature_voConfig::max_move_dist)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.max_3d_dist = 0.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.max_3d_dist = 100.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.max_3d_dist = 30.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<double>("max_3d_dist", "double", 0, "", "", &feature_voConfig::max_3d_dist)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<double>("max_3d_dist", "double", 0, "", "", &feature_voConfig::max_3d_dist)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.numOfIter = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.numOfIter = 100;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.numOfIter = 50;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("numOfIter", "int", 0, "", "", &feature_voConfig::numOfIter)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("numOfIter", "int", 0, "", "", &feature_voConfig::numOfIter)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.subsetSize = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.subsetSize = 20;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.subsetSize = 3;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("subsetSize", "int", 0, "", "", &feature_voConfig::subsetSize)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<int>("subsetSize", "int", 0, "", "", &feature_voConfig::subsetSize)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.inlier_dist_threshold = 0.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.inlier_dist_threshold = 100.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.inlier_dist_threshold = 10.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<double>("inlier_dist_threshold", "double", 0, "", "", &feature_voConfig::inlier_dist_threshold)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<double>("inlier_dist_threshold", "double", 0, "", "", &feature_voConfig::inlier_dist_threshold)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_pcl = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_pcl = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_pcl = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_pcl", "bool", 0, "", "", &feature_voConfig::publish_pcl)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_pcl", "bool", 0, "", "", &feature_voConfig::publish_pcl)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_marker = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_marker = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_marker = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_marker", "bool", 0, "", "", &feature_voConfig::publish_marker)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_marker", "bool", 0, "", "", &feature_voConfig::publish_marker)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_temporalMatchImg = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_temporalMatchImg = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_temporalMatchImg = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_temporalMatchImg", "bool", 0, "", "", &feature_voConfig::publish_temporalMatchImg)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_temporalMatchImg", "bool", 0, "", "", &feature_voConfig::publish_temporalMatchImg)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_stereoMatchImg = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_stereoMatchImg = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_stereoMatchImg = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_stereoMatchImg", "bool", 0, "", "", &feature_voConfig::publish_stereoMatchImg)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_voConfig::AbstractParamDescriptionConstPtr(new feature_voConfig::ParamDescription<bool>("publish_stereoMatchImg", "bool", 0, "", "", &feature_voConfig::publish_stereoMatchImg)));
//#line 231 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 231 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(feature_voConfig::AbstractGroupDescriptionConstPtr(new feature_voConfig::GroupDescription<feature_voConfig::DEFAULT, feature_voConfig>(Default)));
//#line 390 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<feature_voConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<feature_voConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<feature_voConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    feature_voConfig __max__;
    feature_voConfig __min__;
    feature_voConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const feature_voConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static feature_voConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &feature_voConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const feature_voConfig &feature_voConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const feature_voConfig &feature_voConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const feature_voConfig &feature_voConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<feature_voConfig::AbstractParamDescriptionConstPtr> &feature_voConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<feature_voConfig::AbstractGroupDescriptionConstPtr> &feature_voConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const feature_voConfigStatics *feature_voConfig::__get_statics__()
  {
    const static feature_voConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = feature_voConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __FEATURE_VORECONFIGURATOR_H__
