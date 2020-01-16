#ifndef _GLOBAL_H_20200116_
#define _GLOBAL_H_20200116_

#ifdef __cplusplus
#define LIB_NAMESPACE syh
#ifndef  LIB_NAMESPACE  /* user namespace */
# define PREPEND_NAMESPACE(name) ::name
# define USE_NAMESPACE
# define BEGIN_NAMESPACE
# define END_NAMESPACE
# define BEGIN_INCLUDE_NAMESPACE
# define END_INCLUDE_NAMESPACE
# define BEGIN_MOC_NAMESPACE
# define QT_END_MOC_NAMESPACE
# define FORWARD_DECLARE_CLASS(name) class name;
# define FORWARD_DECLARE_STRUCT(name) struct name;
# define MANGLE_NAMESPACE(name) name
#else /* user namespace */
# define PREPEND_NAMESPACE(name) ::LIB_NAMESPACE::name
# define USE_NAMESPACE using namespace ::LIB_NAMESPACE;
# define BEGIN_NAMESPACE namespace LIB_NAMESPACE {
# define END_NAMESPACE }
# define BEGIN_INCLUDE_NAMESPACE }
# define END_INCLUDE_NAMESPACE namespace LIB_NAMESPACE {
# define BEGIN_MOC_NAMESPACE USE_NAMESPACE
# define END_MOC_NAMESPACE
# define FORWARD_DECLARE_CLASS(name) \
    BEGIN_NAMESPACE class name; END_NAMESPACE \
    using PREPEND_NAMESPACE(name);

# define FORWARD_DECLARE_STRUCT(name) \
    BEGIN_NAMESPACE struct name; END_NAMESPACE \
    using PREPEND_NAMESPACE(name);

# define MANGLE_NAMESPACE0(x) x
# define MANGLE_NAMESPACE1(a, b) a##_##b
# define MANGLE_NAMESPACE2(a, b) MANGLE_NAMESPACE1(a,b)
# define MANGLE_NAMESPACE(name) MANGLE_NAMESPACE2( \
         MANGLE_NAMESPACE0(name), MANGLE_NAMESPACE0(QT_NAMESPACE))

#endif /* user namespace */

#else /* __cplusplus */
# define QT_BEGIN_NAMESPACE
# define QT_END_NAMESPACE
# define QT_USE_NAMESPACE
# define QT_BEGIN_INCLUDE_NAMESPACE
# define QT_END_INCLUDE_NAMESPACE
#endif /* __cplusplus */



#endif