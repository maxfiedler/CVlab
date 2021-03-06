//#line 2 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the wurzel_features package 
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


#ifndef __wurzel_features__FEATURE_MATCHERCONFIG_H__
#define __wurzel_features__FEATURE_MATCHERCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace wurzel_features
{
  class feature_matcherConfigStatics;
  
  class feature_matcherConfig
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
      
      virtual void clamp(feature_matcherConfig &config, const feature_matcherConfig &max, const feature_matcherConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const feature_matcherConfig &config1, const feature_matcherConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, feature_matcherConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const feature_matcherConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, feature_matcherConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const feature_matcherConfig &config) const = 0;
      virtual void getValue(const feature_matcherConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T feature_matcherConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (feature_matcherConfig::* field);

      virtual void clamp(feature_matcherConfig &config, const feature_matcherConfig &max, const feature_matcherConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const feature_matcherConfig &config1, const feature_matcherConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, feature_matcherConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const feature_matcherConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, feature_matcherConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const feature_matcherConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const feature_matcherConfig &config, boost::any &val) const
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
      virtual void updateParams(boost::any &cfg, feature_matcherConfig &top) const= 0;
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
      
      virtual void updateParams(boost::any &cfg, feature_matcherConfig &top) const
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
      std::vector<feature_matcherConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(feature_matcherConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = params.begin(); i != params.end(); i++)
      {
        boost::any val;
        (*i)->getValue(config, val);

        if("method"==(*i)->name){method = boost::any_cast<int>(val);}
        if("window_size"==(*i)->name){window_size = boost::any_cast<int>(val);}
        if("threshold"==(*i)->name){threshold = boost::any_cast<double>(val);}
        if("GaussBlur_Radius"==(*i)->name){GaussBlur_Radius = boost::any_cast<int>(val);}
        if("GaussBlur_Sigma"==(*i)->name){GaussBlur_Sigma = boost::any_cast<double>(val);}
        if("number_of_keypoints"==(*i)->name){number_of_keypoints = boost::any_cast<int>(val);}
        if("use_ANMS"==(*i)->name){use_ANMS = boost::any_cast<bool>(val);}
        if("ANMS_Min_Dist"==(*i)->name){ANMS_Min_Dist = boost::any_cast<double>(val);}
      }
    }

    int method;
int window_size;
double threshold;
int GaussBlur_Radius;
double GaussBlur_Sigma;
int number_of_keypoints;
bool use_ANMS;
double ANMS_Min_Dist;

    bool state;
    std::string name;

    
}groups;



//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int method;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int window_size;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double threshold;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int GaussBlur_Radius;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double GaussBlur_Sigma;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int number_of_keypoints;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool use_ANMS;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ANMS_Min_Dist;
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
        ROS_ERROR("feature_matcherConfig::__fromMessage__ called with an unexpected parameter.");
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
      const feature_matcherConfig &__max__ = __getMax__();
      const feature_matcherConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const feature_matcherConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const feature_matcherConfig &__getDefault__();
    static const feature_matcherConfig &__getMax__();
    static const feature_matcherConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const feature_matcherConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void feature_matcherConfig::ParamDescription<std::string>::clamp(feature_matcherConfig &config, const feature_matcherConfig &max, const feature_matcherConfig &min) const
  {
    return;
  }

  class feature_matcherConfigStatics
  {
    friend class feature_matcherConfig;
    
    feature_matcherConfigStatics()
    {
feature_matcherConfig::GroupDescription<feature_matcherConfig::DEFAULT, feature_matcherConfig> Default("Default", "", 0, 0, true, &feature_matcherConfig::groups);
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.method = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.method = 3;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.method = 3;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("method", "int", 0, "A method parameter which is edited via an enum", "{'enum_description': 'An enum to set Method', 'enum': [{'srcline': 8, 'description': 'MOPS and basic matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'MOPS'}, {'srcline': 9, 'description': 'BRIEF and Hamming matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'BRIEF'}, {'srcline': 10, 'description': 'Conventional ORB', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'ORB'}, {'srcline': 11, 'description': 'Wurzel method', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'ORB_EXTEND'}]}", &feature_matcherConfig::method)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("method", "int", 0, "A method parameter which is edited via an enum", "{'enum_description': 'An enum to set Method', 'enum': [{'srcline': 8, 'description': 'MOPS and basic matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'MOPS'}, {'srcline': 9, 'description': 'BRIEF and Hamming matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'BRIEF'}, {'srcline': 10, 'description': 'Conventional ORB', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'ORB'}, {'srcline': 11, 'description': 'Wurzel method', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'ORB_EXTEND'}]}", &feature_matcherConfig::method)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.window_size = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.window_size = 10;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.window_size = 3;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("window_size", "int", 0, "Window size of Harris Detector.", "", &feature_matcherConfig::window_size)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("window_size", "int", 0, "Window size of Harris Detector.", "", &feature_matcherConfig::window_size)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.threshold = 0.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.threshold = 10000.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.threshold = 2200.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("threshold", "double", 0, "A double parameter", "", &feature_matcherConfig::threshold)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("threshold", "double", 0, "A double parameter", "", &feature_matcherConfig::threshold)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.GaussBlur_Radius = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.GaussBlur_Radius = 20;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.GaussBlur_Radius = 4;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("GaussBlur_Radius", "int", 0, "", "", &feature_matcherConfig::GaussBlur_Radius)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("GaussBlur_Radius", "int", 0, "", "", &feature_matcherConfig::GaussBlur_Radius)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.GaussBlur_Sigma = 0.1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.GaussBlur_Sigma = 5.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.GaussBlur_Sigma = 1.3;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("GaussBlur_Sigma", "double", 0, "", "", &feature_matcherConfig::GaussBlur_Sigma)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("GaussBlur_Sigma", "double", 0, "", "", &feature_matcherConfig::GaussBlur_Sigma)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.number_of_keypoints = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.number_of_keypoints = 500;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.number_of_keypoints = 200;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("number_of_keypoints", "int", 0, "", "", &feature_matcherConfig::number_of_keypoints)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<int>("number_of_keypoints", "int", 0, "", "", &feature_matcherConfig::number_of_keypoints)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.use_ANMS = 0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.use_ANMS = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.use_ANMS = 1;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<bool>("use_ANMS", "bool", 0, "", "", &feature_matcherConfig::use_ANMS)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<bool>("use_ANMS", "bool", 0, "", "", &feature_matcherConfig::use_ANMS)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ANMS_Min_Dist = 0.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ANMS_Min_Dist = 100.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ANMS_Min_Dist = 10.0;
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("ANMS_Min_Dist", "double", 0, "", "", &feature_matcherConfig::ANMS_Min_Dist)));
//#line 260 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(feature_matcherConfig::AbstractParamDescriptionConstPtr(new feature_matcherConfig::ParamDescription<double>("ANMS_Min_Dist", "double", 0, "", "", &feature_matcherConfig::ANMS_Min_Dist)));
//#line 231 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 231 "/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(feature_matcherConfig::AbstractGroupDescriptionConstPtr(new feature_matcherConfig::GroupDescription<feature_matcherConfig::DEFAULT, feature_matcherConfig>(Default)));
//#line 390 "/opt/ros/groovy/share/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<feature_matcherConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<feature_matcherConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<feature_matcherConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    feature_matcherConfig __max__;
    feature_matcherConfig __min__;
    feature_matcherConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const feature_matcherConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static feature_matcherConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &feature_matcherConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const feature_matcherConfig &feature_matcherConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const feature_matcherConfig &feature_matcherConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const feature_matcherConfig &feature_matcherConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<feature_matcherConfig::AbstractParamDescriptionConstPtr> &feature_matcherConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<feature_matcherConfig::AbstractGroupDescriptionConstPtr> &feature_matcherConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const feature_matcherConfigStatics *feature_matcherConfig::__get_statics__()
  {
    const static feature_matcherConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = feature_matcherConfigStatics::get_instance();
    
    return statics;
  }

//#line 8 "/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg"
      const int feature_matcher_MOPS = 0;
//#line 9 "/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg"
      const int feature_matcher_BRIEF = 1;
//#line 10 "/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg"
      const int feature_matcher_ORB = 2;
//#line 11 "/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg"
      const int feature_matcher_ORB_EXTEND = 3;
}

#endif // __FEATURE_MATCHERRECONFIGURATOR_H__
