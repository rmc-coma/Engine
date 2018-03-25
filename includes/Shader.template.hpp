#define SHADER_VERSION              "#version 410 core"

#define IN_VERTEX                   "in vec3             in_Vertex;"
#define IN_NORMAL                   "in vec3             in_Normal;"
#define IN_UV                       "in vec2             in_UV;"

#define IN_VERTEX2                  "in vec3             Vertex;"
#define IN_NORMAL2                  "in vec3             Normal;"
#define IN_UV2                      "in vec2             UV;"

#define UNIFORM_MODEL               "uniform mat4        model;"
#define UNIFORM_VIEW                "uniform mat4        view;"
#define UNIFORM_PROJECTION          "uniform mat4        projection;"

#define UNIFORM_DIFFUSE             "uniform vec4        diffuse;"
#define UNIFORM_AMBIENT             "uniform vec4        ambient;"
#define UNIFORM_SPECULAR            "uniform vec4        specular;"
#define UNIFORM_EXPONENT            "uniform float       exponent;"

#define UNIFORM_DIFFUSE_TEXTURE     "uniform sampler2D   diffuse_tex;"
#define UNIFORM_AMBIENT_TEXTURE     "uniform sampler2D   ambient_tex;"
#define UNIFORM_SPECULAR_TEXTURE    "uniform sampler2D   specular_tex;"

#define OUT_VERTEX                  "out vec4            Vertex;"
#define OUT_NORMAL                  "out vec3            Normal;"
#define OUT_UV                      "out vec2            UV;"

#define VERTEX_INSTRUCTIONS         "Vertex = model * view * vec4(in_Geovertex, 1.0f);\ngl_Position = projection * Vertex"
#define NORMAL_INSTRUCTIONS         "Normal = normalize(model * view * vec4(in_Normal, 0.0f)).xyz;"
#define UV_INSTRUCTIONS             "UV = in_UV;"

#define OUT_COLOR                   "out vec4            out_Color;"

#define PHONG_INSTRUCTIONS          "vec3 v = vertex.xyz;\nvec3 N = vernor;\nvec3 L = normalize(vec3(0.0f, 0.0f, 1.0f) - v);\nvec3 E = normalize(-v);\nvec3 R = normalize(-reflect(L,N));"
#define DIFFUSE_TEX_INSTRUCTIONS    "vec4 Idiff = clamp(texture(diffuse_tex, texver) * max(dot(N,L), 0.0), 0.0, 1.0);"
#define AMBIENT_TEX_INSTRUCTIONS    "vec4 Iamb = texture(ambient_tex, texver);"
#define SPECULAR_TEX_INSTRUCTIONS   "vec4 Ispec = clamp(texture(specular_tex, texver) * pow(max(dot(R, E), 0.0), 0.3f), 0.0, 1.0);"
#define SPECULAR_TEX_INSTRUCTIONS_E "vec4 Ispec = clamp(texture(specular_tex, texver) * pow(max(dot(R, E), 0.0), 0.3f * exponent), 0.0, 1.0);"
#define DIFFUSE_INSTRUCTIONS        "vec4 Idiff = clamp(diffuse * max(dot(N,L), 0.0), 0.0, 1.0);"
#define AMBIENT_INSTRUCTIONS        "vec4 Iamb = ambient;"
#define SPECULAR_INSTRUCTIONS       "vec4 Ispec = clamp(specular * pow(max(dot(R, E), 0.0), 0.3f), 0.0, 1.0);"
#define SPECULAR_INSTRUCTIONS_E     "vec4 Ispec = clamp(specular * pow(max(dot(R, E), 0.0), 0.3f * exponent), 0.0, 1.0);"
#define NO_DIFFUSE_INSTRUCTIONS     "vec4 Idiff = 0.0f;"
#define NO_AMBIENT_INSTRUCTIONS     "vec4 Iamb = 0.0f;"
#define NO_SPECULAR_INSTRUCTIONS    "vec4 Ispec = 0.0f;"
#define COLOR_INSTRUCTIONS          "out_Color = Iamb + Idiff + Ispec;"
