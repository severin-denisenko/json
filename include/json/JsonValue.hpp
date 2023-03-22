#ifndef JSON_JSONVALUE_HPP
#define JSON_JSONVALUE_HPP

#include <cstdint>
#include <variant>
#include <memory>
#include <map>
#include <vector>
#include <string>

namespace json{
    class JsonValue;

    using JsonObject = std::map<std::string, std::shared_ptr<JsonValue>>;
    using JsonArray = std::vector<std::shared_ptr<JsonValue>>;
    using JsonNumber = double;
    using JsonString = std::string;
    using JsonBoolean = bool;

    class JsonValue{
    public:
        explicit JsonValue(JsonObject object);
        explicit JsonValue(JsonArray array);
        explicit JsonValue(JsonNumber number);
        explicit JsonValue(JsonString string);
        explicit JsonValue(JsonBoolean boolean);
        JsonValue();

        enum class ValueType : std::size_t {
            OBJECT = 0,
            ARRAY = 1,
            NUMBER = 2,
            STRING = 3,
            BOOLEAN = 4,
            NULL_TYPE
        };

        ValueType GetType();

        JsonObject GetObject();
        JsonArray GetArray();
        JsonNumber GetNumber();
        JsonString GetString();
        JsonBoolean GetBoolean();

        void Set(JsonObject object);
        void Set(JsonArray array);
        void Set(JsonNumber number);
        void Set(JsonString string);
        void Set(JsonBoolean boolean);
    private:
        using Value = std::variant<JsonObject, JsonArray, JsonNumber, JsonString, JsonBoolean>;
        Value value;

        ValueType type;
    };
}

#endif //JSON_JSONVALUE_HPP