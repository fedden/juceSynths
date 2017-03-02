# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../JuceLibraryCode/modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -fPIC -O0
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -Wl,--no-undefined -shared $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := EmptySynth.so
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../JuceLibraryCode/modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -fPIC -O3
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -Wl,--no-undefined -shared -fvisibility=hidden $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := EmptySynth.so
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS := \
  $(JUCE_OBJDIR)/fft_a3fd5dd.o \
  $(JUCE_OBJDIR)/maxiFFT_e00bf898.o \
  $(JUCE_OBJDIR)/maxiMFCC_dca8977f.o \
  $(JUCE_OBJDIR)/maximilian_2739ddb5.o \
  $(JUCE_OBJDIR)/PluginProcessor_a059e380.o \
  $(JUCE_OBJDIR)/PluginEditor_94d4fb09.o \
  $(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o \
  $(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o \
  $(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o \
  $(JUCE_OBJDIR)/juce_audio_plugin_client_utils_35fbf7.o \
  $(JUCE_OBJDIR)/juce_audio_plugin_client_VST2_fd137df.o \
  $(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o \
  $(JUCE_OBJDIR)/juce_core_75b14332.o \
  $(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o \
  $(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o \
  $(JUCE_OBJDIR)/juce_events_d2be882c.o \
  $(JUCE_OBJDIR)/juce_graphics_9c18891e.o \
  $(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o \
  $(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o \
  $(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o \
  $(JUCE_OBJDIR)/juce_video_f128c512.o \

.PHONY: clean

$(JUCE_OUTDIR)/$(TARGET): check-pkg-config $(OBJECTS) $(RESOURCES)
	@echo Linking EmptySynth
	-@mkdir -p $(JUCE_BINDIR)
	-@mkdir -p $(JUCE_LIBDIR)
	-@mkdir -p $(JUCE_OUTDIR)
	@$(BLDCMD)

check-pkg-config:
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa freetype2 libcurl x11 xext xinerama

clean:
	@echo Cleaning EmptySynth
	@$(CLEANCMD)

strip:
	@echo Stripping EmptySynth
	-@$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

$(JUCE_OBJDIR)/fft_a3fd5dd.o: ../../../Maximilian/libs/fft.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling fft.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/maxiFFT_e00bf898.o: ../../../Maximilian/libs/maxiFFT.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling maxiFFT.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/maxiMFCC_dca8977f.o: ../../../Maximilian/libs/maxiMFCC.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling maxiMFCC.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/maximilian_2739ddb5.o: ../../../Maximilian/maximilian.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling maximilian.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginProcessor_a059e380.o: ../../Source/PluginProcessor.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginProcessor.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PluginEditor_94d4fb09.o: ../../Source/PluginEditor.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PluginEditor.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o: ../../JuceLibraryCode/juce_audio_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o: ../../JuceLibraryCode/juce_audio_devices.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o: ../../JuceLibraryCode/juce_audio_formats.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_plugin_client_utils_35fbf7.o: ../../JuceLibraryCode/juce_audio_plugin_client_utils.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_plugin_client_utils.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_plugin_client_VST2_fd137df.o: ../../JuceLibraryCode/juce_audio_plugin_client_VST2.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_plugin_client_VST2.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o: ../../JuceLibraryCode/juce_audio_processors.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_core_75b14332.o: ../../JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o: ../../JuceLibraryCode/juce_cryptography.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o: ../../JuceLibraryCode/juce_data_structures.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_events_d2be882c.o: ../../JuceLibraryCode/juce_events.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_graphics_9c18891e.o: ../../JuceLibraryCode/juce_graphics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o: ../../JuceLibraryCode/juce_gui_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o: ../../JuceLibraryCode/juce_gui_extra.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o: ../../JuceLibraryCode/juce_opengl.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_video_f128c512.o: ../../JuceLibraryCode/juce_video.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
