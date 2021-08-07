/*
 * @Description: Load Dynamic Library 
 * @version: 0.1
 * @Author: Ricardo Lu<shenglu1202@163.com>
 * @Date: 2021-08-07 22:48:25
 * @Last Editor: Ricardo Lu
 * @LastEditTime: 2021-08-08 00:06:08
 */
#ifndef __DL_LOADER_H__
#define __DL_LOADER_H__  

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <dlfcn.h>
#include <string>
#include <mutex>
#include <map>

class DLLoader
{
public:
    DLLoader (const std::string& path, int mode = RTLD_LAZY) {
        assert (!IsEmpty (path.c_str()));
        
        if (!(lib_handle_ = dlopen (path.c_str(), mode))) {
            printf ("Failed to open library:%s (%s)",
                path.c_str(), dlerror());
        }
        
    }

   ~DLLoader () {
        if (lib_handle_) {
            dlclose (lib_handle_);
            lib_handle_ = NULL;
        }
    }

    bool  IsValid () const { 
        return NULL != lib_handle_; 
    }
    
    const std::string& GetPath () const { 
        return lib_path_; 
    }

    template <typename API>
    API GetAPI (const std::string& name)
    {
        std::lock_guard<std::mutex> lock (mutex_);

        auto it = apis_.find (name);
        if (it != apis_.end ()) {
            return (API) it->second;
        }

        if (0 == name.compare("") || !lib_handle_) {
            return NULL;
        }

        void* api = dlsym (lib_handle_, name.c_str());
        if (api) {
            apis_ [name] = api;
        }

        return (API) api;
    }

    template <typename API>
    API GetAPI (const char* name)
    {
        return GetAPI<API> (std::string (name?name:""));
    }

private:
    bool IsEmpty (const char* str)
    {
        return !str || strlen(str) == 0;
    }

private:
    void*             lib_handle_ { NULL };
    const std::string lib_path_   {      };
    std::mutex        mutex_              ;
    std::map<std::string, void*> 
                      apis_       {      };
};

#endif //__DL_LOADER_H__