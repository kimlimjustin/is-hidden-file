#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <node_api.h>
#include <assert.h>
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <codecvt>
using namespace std;

wstring u16stringToWstring(u16string const &str)
{
	wstring_convert<codecvt_utf16<wchar_t, 0x10ffff, little_endian>, wchar_t> conv;
	wstring wstr = conv.from_bytes(reinterpret_cast<const char *> (&str[0]), reinterpret_cast<const char *> (&str[0] + str.size()));
	return wstr;
}

void throwIfNotSuccess(napi_env env, napi_status status, char *msg)
{
	if (status != napi_ok)
	{
		throw napi_throw_error(env, NULL, msg);
	}
}

bool checkHiddenFile(u16string const &FilePath)
{
	wstring path = u16stringToWstring(FilePath);
	DWORD const result = GetFileAttributesW(path.c_str());
	if (result != 0xFFFFFFFF)
	{
		return !!(result & FILE_ATTRIBUTE_HIDDEN);
	}
	else
	{
		return false;
	}
}

napi_value isHiddenFile(napi_env env, napi_callback_info info)
{
	napi_status status;

	size_t argc = 2;
	napi_value argv[2];
	throwIfNotSuccess(env, napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr), "unable to read arguments");

	size_t str_size;
	size_t str_size_read;
	napi_get_value_string_utf16(env, argv[0], NULL, 0, &str_size);
	char16_t *path;
	path = (char16_t *)calloc(str_size + 1, sizeof(char16_t));
	str_size = str_size + 1;
	napi_get_value_string_utf16(env, argv[0], path, str_size, &str_size_read);

	napi_value result;
	status = napi_get_boolean(env, checkHiddenFile(path), &result);
	free(path);
	return result;
}


napi_value Init(napi_env env, napi_value exports){
	napi_value fn;
	throwIfNotSuccess(env, napi_create_function(env, "isHiddenFile", sizeof("isHiddenFile"), isHiddenFile, NULL, &fn), "Unable to wrap native function");

	throwIfNotSuccess(env, napi_set_named_property(env, exports, "isHiddenFile", fn), "Unable to populate exports");

}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)