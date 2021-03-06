//  -------------------------------------------------------------------------
//  Copyright (C) 2014 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#include "Platform_Base/Window_Base.h"
#include "Collections/StringOutputStream.h"

#include "RendererLib/DisplayConfig.h"
#include "RendererAPI/IWindowEventHandler.h"

namespace ramses_internal
{
    Window_Base::Window_Base(const DisplayConfig& displayConfig, IWindowEventHandler& eventHandler, UInt32 id)
        : m_windowName((StringOutputStream() << "RAMSES Renderer " << id).release())
        , m_eventHandler(eventHandler)
        , m_fullscreen(displayConfig.getFullscreenState())
        , m_borderless(displayConfig.getBorderlessState())
        , m_offscreen(displayConfig.getOffscreen())
        , m_msaaSampleCount(1)
        , m_width(displayConfig.getDesiredWindowWidth())
        , m_height(displayConfig.getDesiredWindowHeight())
        , m_posX(displayConfig.getWindowPositionX())
        , m_posY(displayConfig.getWindowPositionY())
        , m_integrityEglDisplayID(displayConfig.getIntegrityEGLDisplayID())
        , m_waylandIviSurfaceID(displayConfig.getWaylandIviSurfaceID())
        , m_resizable(displayConfig.isResizable())
    {
        if (displayConfig.getAntialiasingMethod() == EAntiAliasingMethod_MultiSampling)
        {
            // Proper MSAA config is done on higher abstraction levels
            m_msaaSampleCount = displayConfig.getAntialiasingSampleCount();
            assert(m_msaaSampleCount > 0);
        }
    }

    Bool Window_Base::canRenderNewFrame() const
    {
        return true;
    }

    void Window_Base::frameRendered()
    {
    }

    const String& Window_Base::getTitle() const
    {
        return m_windowName;
    }

    void Window_Base::setTitle(const String& title)
    {
        m_windowName = title;
    }

    UInt32 Window_Base::getMSAASampleCount() const
    {
        return m_msaaSampleCount;
    }

    IntegrityEglDisplayId Window_Base::getIntegrityEGLDisplayID() const
    {
        return m_integrityEglDisplayID;
    }

    WaylandIviSurfaceId Window_Base::getWaylandIviSurfaceID() const
    {
        return m_waylandIviSurfaceID;
    }

    Bool Window_Base::isOffscreen() const
    {
        return m_offscreen;
    }

    UInt32 Window_Base::getWidth() const
    {
        return m_width;
    }

    UInt32 Window_Base::getHeight() const
    {
        return m_height;
    }

    Float Window_Base::getAspectRatio() const
    {
        return static_cast<Float>(m_width) / m_height;
    }

    Int32 Window_Base::getPosX() const
    {
        return m_posX;
    }

    Int32 Window_Base::getPosY() const
    {
        return m_posY;
    }
}
