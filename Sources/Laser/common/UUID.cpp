#include <Laser/UUID.h>
#include <boost/uuid/uuid_generators.hpp>

namespace Laser
{
	const UUID UUIDS::IUNKNOWN = boost::uuids::random_generator()();
	const UUID UUIDS::IBUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::OBJECT = boost::uuids::random_generator()();
	const UUID UUIDS::VERTEX_BUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::SHADER_UNIFORM_BUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::TEXTURE_BUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::RESOURCE_IMANAGER = boost::uuids::random_generator()();
	const UUID UUIDS::RESOURCE_MANAGER = boost::uuids::random_generator()();
	
	const UUID UUIDS::OPENGL_VERTEX_SHADER = boost::uuids::random_generator()();
	const UUID UUIDS::OPENGL_FRAGMENT_SHADER = boost::uuids::random_generator()();
	const UUID UUIDS::OPENGL_VERTEX_BUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::OPENGL_SHADER_UNIFORM_BUFFER = boost::uuids::random_generator()();
	const UUID UUIDS::OPENGL_TEXTURE = boost::uuids::random_generator()();

}
