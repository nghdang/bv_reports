from conans import ConanFile, CMake


class BVReports(ConanFile):
    name = "BV Reports"
    version = "0.0.1"
    generators = "cmake"
    settings = "os", "arch", "compiler", "build_type"
    export_sources = ["CMakeLists.txt", "*.cpp", "*.hpp", "*.h"]

    def build(self):
        cmake = CMake(self)
        cmake.generator = "Ninja"
        cmake.configure()
        cmake.build()
