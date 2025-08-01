#include "imgui.h"
#include "imgui_internal.h"

#ifndef ZGUI_API
#define ZGUI_API
#endif

//--------------------------------------------------------------------------------------------------
//
// ImGui
//
//--------------------------------------------------------------------------------------------------
extern "C"
{

    /*
    #include <stdio.h>

    ZGUI_API float zguiGetFloatMin(void) {
        printf("__FLT_MIN__ %.32e\n", __FLT_MIN__);
        return __FLT_MIN__;
    }

    ZGUI_API float zguiGetFloatMax(void) {
        printf("__FLT_MAX__ %.32e\n", __FLT_MAX__);
        return __FLT_MAX__;
    }
    */

    ZGUI_API void zguiSetAllocatorFunctions(
        void *(*alloc_func)(size_t, void *),
        void (*free_func)(void *, void *))
    {
        ImGui::SetAllocatorFunctions(alloc_func, free_func, nullptr);
    }

    ZGUI_API void zguiSetNextWindowViewport(ImGuiID viewport_id)
    {
        ImGui::SetNextWindowViewport(viewport_id);
    }

    ZGUI_API void zguiSetNextWindowPos(float x, float y, ImGuiCond cond, float pivot_x, float pivot_y)
    {
        ImGui::SetNextWindowPos({x, y}, cond, {pivot_x, pivot_y});
    }

    ZGUI_API void zguiSetNextWindowSize(float w, float h, ImGuiCond cond)
    {
        ImGui::SetNextWindowSize({w, h}, cond);
    }

    ZGUI_API void zguiSetNextWindowContentSize(float w, float h)
    {
        ImGui::SetNextWindowContentSize({w, h});
    }

    ZGUI_API void zguiSetNextWindowCollapsed(bool collapsed, ImGuiCond cond)
    {
        ImGui::SetNextWindowCollapsed(collapsed, cond);
    }

    ZGUI_API void zguiSetNextWindowFocus(void)
    {
        ImGui::SetNextWindowFocus();
    }
    
    ZGUI_API void zguiSetNextWindowScroll(float scroll_x, float scroll_y)
    {
        ImGui::SetNextWindowScroll({scroll_x, scroll_y});
    }

    ZGUI_API void zguiSetNextWindowBgAlpha(float alpha)
    {
        ImGui::SetNextWindowBgAlpha(alpha);
    }

    ZGUI_API void zguiSetWindowFocus(const char *name)
    {
        ImGui::SetWindowFocus(name);
    }

    ZGUI_API void zguiSetWindowFontScale(float scale) 
    {
        ImGui::SetWindowFontScale(scale);
    }

    ZGUI_API void zguiSetKeyboardFocusHere(int offset)
    {
        ImGui::SetKeyboardFocusHere(offset);
    }

    ZGUI_API void zguiSetNavCursorVisible(bool visible) 
    {
        ImGui::SetNavCursorVisible(visible);
    }

    ZGUI_API void zguiSetNextItemAllowOverlap() 
    {
        ImGui::SetNextItemAllowOverlap();
    }

    ZGUI_API bool zguiBegin(const char *name, bool *p_open, ImGuiWindowFlags flags)
    {
        return ImGui::Begin(name, p_open, flags);
    }

    ZGUI_API void zguiEnd(void)
    {
        ImGui::End();
    }

    ZGUI_API bool zguiBeginChild(const char *str_id, float w, float h, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags)
    {
        return ImGui::BeginChild(str_id, {w, h}, child_flags, window_flags);
    }

    ZGUI_API bool zguiBeginChildId(ImGuiID id, float w, float h, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags)
    {
        return ImGui::BeginChild(id, {w, h}, child_flags, window_flags);
    }

    ZGUI_API void zguiEndChild(void)
    {
        ImGui::EndChild();
    }

    ZGUI_API float zguiGetScrollX(void)
    {
        return ImGui::GetScrollX();
    }

    ZGUI_API float zguiGetScrollY(void)
    {
        return ImGui::GetScrollY();
    }

    ZGUI_API void zguiSetScrollX(float scroll_x)
    {
        ImGui::SetScrollX(scroll_x);
    }

    ZGUI_API void zguiSetScrollY(float scroll_y)
    {
        ImGui::SetScrollY(scroll_y);
    }

    ZGUI_API float zguiGetScrollMaxX(void)
    {
        return ImGui::GetScrollMaxX();
    }

    ZGUI_API float zguiGetScrollMaxY(void)
    {
        return ImGui::GetScrollMaxY();
    }

    ZGUI_API void zguiSetScrollHereX(float center_x_ratio)
    {
        ImGui::SetScrollHereX(center_x_ratio);
    }

    ZGUI_API void zguiSetScrollHereY(float center_y_ratio)
    {
        ImGui::SetScrollHereY(center_y_ratio);
    }

    ZGUI_API void zguiSetScrollFromPosX(float local_x, float center_x_ratio)
    {
        ImGui::SetScrollFromPosX(local_x, center_x_ratio);
    }

    ZGUI_API void zguiSetScrollFromPosY(float local_y, float center_y_ratio)
    {
        ImGui::SetScrollFromPosY(local_y, center_y_ratio);
    }

    ZGUI_API bool zguiIsWindowAppearing(void)
    {
        return ImGui::IsWindowAppearing();
    }

    ZGUI_API bool zguiIsWindowCollapsed(void)
    {
        return ImGui::IsWindowCollapsed();
    }

    ZGUI_API bool zguiIsWindowFocused(ImGuiFocusedFlags flags)
    {
        return ImGui::IsWindowFocused(flags);
    }

    ZGUI_API bool zguiIsWindowHovered(ImGuiHoveredFlags flags)
    {
        return ImGui::IsWindowHovered(flags);
    }

    ZGUI_API void zguiGetWindowPos(float pos[2])
    {
        const ImVec2 p = ImGui::GetWindowPos();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiGetWindowSize(float size[2])
    {
        const ImVec2 s = ImGui::GetWindowSize();
        size[0] = s.x;
        size[1] = s.y;
    }

    ZGUI_API float zguiGetWindowWidth(void)
    {
        return ImGui::GetWindowWidth();
    }

    ZGUI_API float zguiGetWindowHeight(void)
    {
        return ImGui::GetWindowHeight();
    }

    ZGUI_API void zguiGetMouseDragDelta(ImGuiMouseButton button, float lock_threshold, float delta[2])
    {
        const ImVec2 d = ImGui::GetMouseDragDelta(button, lock_threshold);
        delta[0] = d.x;
        delta[1] = d.y;
    }

    ZGUI_API void zguiResetMouseDragDelta(ImGuiMouseButton button)
    {
        ImGui::ResetMouseDragDelta(button);
    }

    ZGUI_API void zguiSpacing(void)
    {
        ImGui::Spacing();
    }

    ZGUI_API void zguiNewLine(void)
    {
        ImGui::NewLine();
    }

    ZGUI_API void zguiIndent(float indent_w)
    {
        ImGui::Indent(indent_w);
    }

    ZGUI_API void zguiUnindent(float indent_w)
    {
        ImGui::Unindent(indent_w);
    }

    ZGUI_API void zguiSeparator(void)
    {
        ImGui::Separator();
    }

    ZGUI_API void zguiSeparatorText(const char *label)
    {
        ImGui::SeparatorText(label);
    }

    ZGUI_API void zguiSameLine(float offset_from_start_x, float spacing)
    {
        ImGui::SameLine(offset_from_start_x, spacing);
    }

    ZGUI_API void zguiDummy(float w, float h)
    {
        ImGui::Dummy({w, h});
    }

    ZGUI_API void zguiBeginGroup(void)
    {
        ImGui::BeginGroup();
    }

    ZGUI_API void zguiEndGroup(void)
    {
        ImGui::EndGroup();
    }

    ZGUI_API void zguiGetItemRectMax(float rect[2])
    {
        const ImVec2 r = ImGui::GetItemRectMax();
        rect[0] = r.x;
        rect[1] = r.y;
    }

    ZGUI_API void zguiGetItemRectMin(float rect[2])
    {
        const ImVec2 r = ImGui::GetItemRectMin();
        rect[0] = r.x;
        rect[1] = r.y;
    }

    ZGUI_API void zguiGetItemRectSize(float rect[2])
    {
        const ImVec2 r = ImGui::GetItemRectSize();
        rect[0] = r.x;
        rect[1] = r.y;
    }

    ZGUI_API void zguiGetCursorPos(float pos[2])
    {
        const ImVec2 p = ImGui::GetCursorPos();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API float zguiGetCursorPosX(void)
    {
        return ImGui::GetCursorPosX();
    }

    ZGUI_API float zguiGetCursorPosY(void)
    {
        return ImGui::GetCursorPosY();
    }

    ZGUI_API void zguiSetCursorPos(float local_x, float local_y)
    {
        ImGui::SetCursorPos({local_x, local_y});
    }

    ZGUI_API void zguiSetCursorPosX(float local_x)
    {
        ImGui::SetCursorPosX(local_x);
    }

    ZGUI_API void zguiSetCursorPosY(float local_y)
    {
        ImGui::SetCursorPosY(local_y);
    }

    ZGUI_API void zguiGetCursorStartPos(float pos[2])
    {
        const ImVec2 p = ImGui::GetCursorStartPos();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiGetCursorScreenPos(float pos[2])
    {
        const ImVec2 p = ImGui::GetCursorScreenPos();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiSetCursorScreenPos(float screen_x, float screen_y)
    {
        ImGui::SetCursorScreenPos({screen_x, screen_y});
    }

    ZGUI_API int zguiGetMouseCursor(void)
    {
        return ImGui::GetMouseCursor();
    }

    ZGUI_API void zguiSetMouseCursor(int cursor)
    {
        ImGui::SetMouseCursor(cursor);
    }

    ZGUI_API void zguiSetNextFrameWantCaptureMouse(bool want_capture_mouse)
    {
        ImGui::SetNextFrameWantCaptureMouse(want_capture_mouse);
    }

    ZGUI_API void zguiGetMousePos(float pos[2])
    {
        const ImVec2 p = ImGui::GetMousePos();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiAlignTextToFramePadding(void)
    {
        ImGui::AlignTextToFramePadding();
    }

    ZGUI_API float zguiGetTextLineHeight(void)
    {
        return ImGui::GetTextLineHeight();
    }

    ZGUI_API float zguiGetTextLineHeightWithSpacing(void)
    {
        return ImGui::GetTextLineHeightWithSpacing();
    }

    ZGUI_API float zguiGetFrameHeight(void)
    {
        return ImGui::GetFrameHeight();
    }

    ZGUI_API float zguiGetFrameHeightWithSpacing(void)
    {
        return ImGui::GetFrameHeightWithSpacing();
    }

    ZGUI_API bool zguiDragFloat(
        const char *label,
        float *v,
        float v_speed,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragFloat2(
        const char *label,
        float v[2],
        float v_speed,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragFloat2(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragFloat3(
        const char *label,
        float v[3],
        float v_speed,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragFloat3(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragFloat4(
        const char *label,
        float v[4],
        float v_speed,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragFloatRange2(
        const char *label,
        float *v_current_min,
        float *v_current_max,
        float v_speed,
        float v_min,
        float v_max,
        const char *format,
        const char *format_max,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragFloatRange2(
            label,
            v_current_min,
            v_current_max,
            v_speed,
            v_min,
            v_max,
            format,
            format_max,
            flags);
    }

    ZGUI_API bool zguiDragInt(
        const char *label,
        int *v,
        float v_speed,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragInt(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragInt2(
        const char *label,
        int v[2],
        float v_speed,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragInt2(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragInt3(
        const char *label,
        int v[3],
        float v_speed,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragInt3(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragInt4(
        const char *label,
        int v[4],
        float v_speed,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragInt4(label, v, v_speed, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiDragIntRange2(
        const char *label,
        int *v_current_min,
        int *v_current_max,
        float v_speed,
        int v_min,
        int v_max,
        const char *format,
        const char *format_max,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragIntRange2(
            label,
            v_current_min,
            v_current_max,
            v_speed,
            v_min,
            v_max,
            format,
            format_max,
            flags);
    }

    ZGUI_API bool zguiDragScalar(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        float v_speed,
        const void *p_min,
        const void *p_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragScalar(label, data_type, p_data, v_speed, p_min, p_max, format, flags);
    }

    ZGUI_API bool zguiDragScalarN(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        int components,
        float v_speed,
        const void *p_min,
        const void *p_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::DragScalarN(label, data_type, p_data, components, v_speed, p_min, p_max, format, flags);
    }

    ZGUI_API bool zguiBeginDragDropSource(ImGuiDragDropFlags flags = 0)
    {
        return ImGui::BeginDragDropSource(flags);
    }
    ZGUI_API bool zguiSetDragDropPayload(
        const char *type,
        const void *data,
        size_t sz,
        ImGuiCond cond = 0)
    {
        return ImGui::SetDragDropPayload(type, data, sz, cond);
    }
    ZGUI_API void zguiEndDragDropSource()
    {
        return ImGui::EndDragDropSource();
    }
    ZGUI_API bool zguiBeginDragDropTarget()
    {
        return ImGui::BeginDragDropTarget();
    }
    ZGUI_API const ImGuiPayload *zguiAcceptDragDropPayload(
        const char *type,
        ImGuiDragDropFlags flags = 0)
    {
        return ImGui::AcceptDragDropPayload(type);
    }
    ZGUI_API void zguiEndDragDropTarget()
    {
        return ImGui::EndDragDropTarget();
    }
    ZGUI_API const ImGuiPayload *zguiGetDragDropPayload()
    {
        return ImGui::GetDragDropPayload();
    }

    ZGUI_API void zguiImGuiPayload_Clear(ImGuiPayload *payload) { payload->Clear(); }

    ZGUI_API bool zguiImGuiPayload_IsDataType(const ImGuiPayload *payload, const char *type)
    {
        return payload->IsDataType(type);
    }

    ZGUI_API bool zguiImGuiPayload_IsPreview(const ImGuiPayload *payload)
    {
        return payload->IsPreview();
    }

    ZGUI_API bool zguiImGuiPayload_IsDelivery(const ImGuiPayload *payload)
    {
        return payload->IsDelivery();
    }

    ZGUI_API bool zguiCombo(
        const char *label,
        int *current_item,
        const char *items_separated_by_zeros,
        int popup_max_height_in_items)
    {
        return ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items);
    }

    ZGUI_API bool zguiBeginCombo(const char *label, const char *preview_value, ImGuiComboFlags flags)
    {
        return ImGui::BeginCombo(label, preview_value, flags);
    }

    ZGUI_API void zguiEndCombo(void)
    {
        ImGui::EndCombo();
    }

    ZGUI_API bool zguiBeginListBox(const char *label, float w, float h)
    {
        return ImGui::BeginListBox(label, {w, h});
    }

    ZGUI_API void zguiEndListBox(void)
    {
        ImGui::EndListBox();
    }

    ZGUI_API bool zguiListBox(const char* label, int* current_item, const char* const items[], int items_count, int height_in_items) 
    {
        return ImGui::ListBox(label, current_item, items, items_count, height_in_items);
    }

    ZGUI_API bool zguiSelectable(const char *label, bool selected, ImGuiSelectableFlags flags, float w, float h)
    {
        return ImGui::Selectable(label, selected, flags, {w, h});
    }

    ZGUI_API bool zguiSelectableStatePtr(
        const char *label,
        bool *p_selected,
        ImGuiSelectableFlags flags,
        float w,
        float h)
    {
        return ImGui::Selectable(label, p_selected, flags, {w, h});
    }

    ZGUI_API bool zguiSliderFloat(
        const char *label,
        float *v,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderFloat(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderFloat2(
        const char *label,
        float v[2],
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderFloat2(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderFloat3(
        const char *label,
        float v[3],
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderFloat3(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderFloat4(
        const char *label,
        float v[4],
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderFloat4(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderInt(
        const char *label,
        int *v,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderInt(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderInt2(
        const char *label,
        int v[2],
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderInt2(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderInt3(
        const char *label,
        int v[3],
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderInt3(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderInt4(
        const char *label,
        int v[4],
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderInt4(label, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiSliderScalar(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        const void *p_min,
        const void *p_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderScalar(label, data_type, p_data, p_min, p_max, format, flags);
    }

    ZGUI_API bool zguiSliderScalarN(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        int components,
        const void *p_min,
        const void *p_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderScalarN(label, data_type, p_data, components, p_min, p_max, format, flags);
    }

    ZGUI_API bool zguiVSliderFloat(
        const char *label,
        float w,
        float h,
        float *v,
        float v_min,
        float v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::VSliderFloat(label, {w, h}, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiVSliderInt(
        const char *label,
        float w,
        float h,
        int *v,
        int v_min,
        int v_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::VSliderInt(label, {w, h}, v, v_min, v_max, format, flags);
    }

    ZGUI_API bool zguiVSliderScalar(
        const char *label,
        float w,
        float h,
        ImGuiDataType data_type,
        void *p_data,
        const void *p_min,
        const void *p_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::VSliderScalar(label, {w, h}, data_type, p_data, p_min, p_max, format, flags);
    }

    ZGUI_API bool zguiSliderAngle(
        const char *label,
        float *v_rad,
        float v_degrees_min,
        float v_degrees_max,
        const char *format,
        ImGuiSliderFlags flags)
    {
        return ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format, flags);
    }

    ZGUI_API ImGuiInputTextCallbackData zguiInputTextCallbackData_Init(void)
    {
        return ImGuiInputTextCallbackData();
    }

    ZGUI_API void zguiInputTextCallbackData_DeleteChars(
        ImGuiInputTextCallbackData *data,
        int pos,
        int bytes_count)
    {
        data->DeleteChars(pos, bytes_count);
    }

    ZGUI_API void zguiInputTextCallbackData_InsertChars(
        ImGuiInputTextCallbackData *data,
        int pos,
        const char *text,
        const char *text_end)
    {
        data->InsertChars(pos, text, text_end);
    }

    ZGUI_API bool zguiInputText(
        const char *label,
        char *buf,
        size_t buf_size,
        ImGuiInputTextFlags flags,
        ImGuiInputTextCallback callback,
        void *user_data)
    {
        return ImGui::InputText(label, buf, buf_size, flags, callback, user_data);
    }

    ZGUI_API bool zguiInputTextMultiline(
        const char *label,
        char *buf,
        size_t buf_size,
        float w,
        float h,
        ImGuiInputTextFlags flags,
        ImGuiInputTextCallback callback,
        void *user_data)
    {
        return ImGui::InputTextMultiline(label, buf, buf_size, {w, h}, flags, callback, user_data);
    }

    ZGUI_API bool zguiInputTextWithHint(
        const char *label,
        const char *hint,
        char *buf,
        size_t buf_size,
        ImGuiInputTextFlags flags,
        ImGuiInputTextCallback callback,
        void *user_data)
    {
        return ImGui::InputTextWithHint(label, hint, buf, buf_size, flags, callback, user_data);
    }

    ZGUI_API bool zguiInputFloat(
        const char *label,
        float *v,
        float step,
        float step_fast,
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputFloat(label, v, step, step_fast, format, flags);
    }

    ZGUI_API bool zguiInputFloat2(
        const char *label,
        float v[2],
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputFloat2(label, v, format, flags);
    }

    ZGUI_API bool zguiInputFloat3(
        const char *label,
        float v[3],
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputFloat3(label, v, format, flags);
    }

    ZGUI_API bool zguiInputFloat4(
        const char *label,
        float v[4],
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputFloat4(label, v, format, flags);
    }

    ZGUI_API bool zguiInputInt(
        const char *label,
        int *v,
        int step,
        int step_fast,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputInt(label, v, step, step_fast, flags);
    }

    ZGUI_API bool zguiInputInt2(const char *label, int v[2], ImGuiInputTextFlags flags)
    {
        return ImGui::InputInt2(label, v, flags);
    }

    ZGUI_API bool zguiInputInt3(const char *label, int v[3], ImGuiInputTextFlags flags)
    {
        return ImGui::InputInt3(label, v, flags);
    }

    ZGUI_API bool zguiInputInt4(const char *label, int v[4], ImGuiInputTextFlags flags)
    {
        return ImGui::InputInt4(label, v, flags);
    }

    ZGUI_API bool zguiInputDouble(
        const char *label,
        double *v,
        double step,
        double step_fast,
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputDouble(label, v, step, step_fast, format, flags);
    }

    ZGUI_API bool zguiInputScalar(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        const void *p_step,
        const void *p_step_fast,
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputScalar(label, data_type, p_data, p_step, p_step_fast, format, flags);
    }

    ZGUI_API bool zguiInputScalarN(
        const char *label,
        ImGuiDataType data_type,
        void *p_data,
        int components,
        const void *p_step,
        const void *p_step_fast,
        const char *format,
        ImGuiInputTextFlags flags)
    {
        return ImGui::InputScalarN(label, data_type, p_data, components, p_step, p_step_fast, format, flags);
    }

    ZGUI_API bool zguiColorEdit3(const char *label, float col[3], ImGuiColorEditFlags flags)
    {
        return ImGui::ColorEdit3(label, col, flags);
    }

    ZGUI_API bool zguiColorEdit4(const char *label, float col[4], ImGuiColorEditFlags flags)
    {
        return ImGui::ColorEdit4(label, col, flags);
    }

    ZGUI_API bool zguiColorPicker3(const char *label, float col[3], ImGuiColorEditFlags flags)
    {
        return ImGui::ColorPicker3(label, col, flags);
    }

    ZGUI_API bool zguiColorPicker4(const char *label, float col[4], ImGuiColorEditFlags flags, const float *ref_col)
    {
        return ImGui::ColorPicker4(label, col, flags, ref_col);
    }

    ZGUI_API bool zguiColorButton(const char *desc_id, const float col[4], ImGuiColorEditFlags flags, float w, float h)
    {
        return ImGui::ColorButton(desc_id, {col[0], col[1], col[2], col[3]}, flags, {w, h});
    }

    ZGUI_API void zguiTextUnformatted(const char *text, const char *text_end)
    {
        ImGui::TextUnformatted(text, text_end);
    }

    ZGUI_API void zguiTextColored(const float col[4], const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGui::TextColoredV({col[0], col[1], col[2], col[3]}, fmt, args);
        va_end(args);
    }

    ZGUI_API void zguiTextDisabled(const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGui::TextDisabledV(fmt, args);
        va_end(args);
    }

    ZGUI_API void zguiTextWrapped(const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGui::TextWrappedV(fmt, args);
        va_end(args);
    }

    ZGUI_API void zguiBulletText(const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGui::BulletTextV(fmt, args);
        va_end(args);
    }

    ZGUI_API void zguiLabelText(const char *label, const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        ImGui::LabelTextV(label, fmt, args);
        va_end(args);
    }

    ZGUI_API void zguiCalcTextSize(
        const char *txt,
        const char *txt_end,
        bool hide_text_after_double_hash,
        float wrap_width,
        float *out_w,
        float *out_h)
    {
        assert(out_w && out_h);
        const ImVec2 s = ImGui::CalcTextSize(txt, txt_end, hide_text_after_double_hash, wrap_width);
        *out_w = s.x;
        *out_h = s.y;
    }

    ZGUI_API bool zguiButton(const char *label, float x, float y)
    {
        return ImGui::Button(label, {x, y});
    }

    ZGUI_API bool zguiSmallButton(const char *label)
    {
        return ImGui::SmallButton(label);
    }

    ZGUI_API bool zguiInvisibleButton(const char *str_id, float w, float h, ImGuiButtonFlags flags)
    {
        return ImGui::InvisibleButton(str_id, {w, h}, flags);
    }

    ZGUI_API bool zguiArrowButton(const char *str_id, ImGuiDir dir)
    {
        return ImGui::ArrowButton(str_id, dir);
    }

    ZGUI_API void zguiImage(
        ImTextureID user_texture_id,
        float w,
        float h,
        const float uv0[2],
        const float uv1[2],
        const float tint_col[4],
        const float border_col[4])
    {
        ImGui::Image(
            user_texture_id,
            {w, h},
            {uv0[0], uv0[1]},
            {uv1[0], uv1[1]},
            {tint_col[0], tint_col[1], tint_col[2], tint_col[3]},
            {border_col[0], border_col[1], border_col[2], border_col[3]});
    }

    ZGUI_API bool zguiImageButton(
        const char *str_id,
        ImTextureID user_texture_id,
        float w,
        float h,
        const float uv0[2],
        const float uv1[2],
        const float bg_col[4],
        const float tint_col[4])
    {
        return ImGui::ImageButton(
            str_id,
            user_texture_id,
            {w, h},
            {uv0[0], uv0[1]},
            {uv1[0], uv1[1]},
            {bg_col[0], bg_col[1], bg_col[2], bg_col[3]},
            {tint_col[0], tint_col[1], tint_col[2], tint_col[3]});
    }

    ZGUI_API void zguiBullet(void)
    {
        ImGui::Bullet();
    }

    ZGUI_API bool zguiRadioButton(const char *label, bool active)
    {
        return ImGui::RadioButton(label, active);
    }

    ZGUI_API bool zguiRadioButtonStatePtr(const char *label, int *v, int v_button)
    {
        return ImGui::RadioButton(label, v, v_button);
    }

    ZGUI_API bool zguiCheckbox(const char *label, bool *v)
    {
        return ImGui::Checkbox(label, v);
    }

    ZGUI_API bool zguiCheckboxBits(const char *label, unsigned int *bits, unsigned int bits_value)
    {
        return ImGui::CheckboxFlags(label, bits, bits_value);
    }

    ZGUI_API void zguiProgressBar(float fraction, float w, float h, const char *overlay)
    {
        return ImGui::ProgressBar(fraction, {w, h}, overlay);
    }

    ZGUI_API bool zguiTextLink(const char* label) {
        return ImGui::TextLink(label) ;
    }

    ZGUI_API void zguiTextLinkOpenURL(const char* label, const char* url) {
        ImGui::TextLinkOpenURL(label, url) ;
    }

    ZGUI_API ImGuiContext *zguiCreateContext(ImFontAtlas *shared_font_atlas)
    {
        return ImGui::CreateContext(shared_font_atlas);
    }

    ZGUI_API void zguiDestroyContext(ImGuiContext *ctx)
    {
        ImGui::DestroyContext(ctx);
    }

    ZGUI_API ImGuiContext *zguiGetCurrentContext(void)
    {
        return ImGui::GetCurrentContext();
    }

    ZGUI_API void zguiSetCurrentContext(ImGuiContext *ctx)
    {
        ImGui::SetCurrentContext(ctx);
    }

    ZGUI_API void zguiNewFrame(void)
    {
        ImGui::NewFrame();
    }

    ZGUI_API void zguiEndFrame(void)
    {
        ImGui::EndFrame();
    }

    ZGUI_API void zguiRender(void)
    {
        ImGui::Render();
    }

    ZGUI_API ImDrawData *zguiGetDrawData(void)
    {
        return ImGui::GetDrawData();
    }

    ZGUI_API void zguiShowDemoWindow(bool *p_open)
    {
        ImGui::ShowDemoWindow(p_open);
    }

    ZGUI_API void zguiShowMetricsWindow(bool* p_open) {
        ImGui::ShowMetricsWindow(p_open);
    }

    ZGUI_API void zguiBeginDisabled(bool disabled)
    {
        ImGui::BeginDisabled(disabled);
    }

    ZGUI_API void zguiEndDisabled(void)
    {
        ImGui::EndDisabled();
    }

    ZGUI_API ImGuiListClipper zguiListClipper_Init()
    {
        return ImGuiListClipper();
    }

    ZGUI_API void zguiListClipper_Begin(ImGuiListClipper *clipper, int items_count, float items_height)
    {
        clipper->Begin(items_count, items_height);
    }

    ZGUI_API void zguiListClipper_End(ImGuiListClipper *clipper)
    {
        clipper->End();
    }

    ZGUI_API void zguiListClipper_IncludeItemsByIndex(ImGuiListClipper *clipper, int item_begin, int item_end)
    {
        clipper->IncludeItemsByIndex(item_begin, item_end);
    }

    ZGUI_API bool zguiListClipper_Step(ImGuiListClipper *clipper)
    {
        return clipper->Step();
    }

    ZGUI_API ImGuiStyle *zguiGetStyle(void)
    {
        return &ImGui::GetStyle();
    }

    ZGUI_API ImGuiStyle zguiStyle_Init(void)
    {
        return ImGuiStyle();
    }

    ZGUI_API void zguiStyle_ScaleAllSizes(ImGuiStyle *style, float scale_factor)
    {
        style->ScaleAllSizes(scale_factor);
    }

    ZGUI_API void zguiStyleColorsDark(ImGuiStyle *style)
    {
        ImGui::StyleColorsDark(style);
    }

    ZGUI_API void zguiStyleColorsLight(ImGuiStyle *style)
    {
        ImGui::StyleColorsLight(style);
    }

    ZGUI_API void zguiStyleColorsClassic(ImGuiStyle *style)
    {
        ImGui::StyleColorsClassic(style);
    }

    ZGUI_API void zguiPushStyleColor4f(ImGuiCol idx, const float col[4])
    {
        ImGui::PushStyleColor(idx, {col[0], col[1], col[2], col[3]});
    }

    ZGUI_API void zguiPushStyleColor1u(ImGuiCol idx, ImU32 col)
    {
        ImGui::PushStyleColor(idx, col);
    }

    ZGUI_API void zguiPopStyleColor(int count)
    {
        ImGui::PopStyleColor(count);
    }

    ZGUI_API void zguiPushStyleVar1f(ImGuiStyleVar idx, float var)
    {
        ImGui::PushStyleVar(idx, var);
    }

    ZGUI_API void zguiPushStyleVar2f(ImGuiStyleVar idx, const float var[2])
    {
        ImGui::PushStyleVar(idx, {var[0], var[1]});
    }

    ZGUI_API void zguiPopStyleVar(int count)
    {
        ImGui::PopStyleVar(count);
    }

    ZGUI_API void zguiPushItemFlag(int item_flag, bool enabled)
    {
        ImGui::PushItemFlag(item_flag, enabled);
    }

    ZGUI_API void zguiPopItemFlag()
    {
        ImGui::PopItemFlag();
    }

    ZGUI_API void zguiPushItemWidth(float item_width)
    {
        ImGui::PushItemWidth(item_width);
    }

    ZGUI_API void zguiPopItemWidth(void)
    {
        ImGui::PopItemWidth();
    }

    ZGUI_API void zguiSetNextItemWidth(float item_width)
    {
        ImGui::SetNextItemWidth(item_width);
    }

    ZGUI_API void zguiSetItemDefaultFocus(void)
    {
        ImGui::SetItemDefaultFocus();
    }

    ZGUI_API ImFont *zguiGetFont(void)
    {
        return ImGui::GetFont();
    }

    ZGUI_API float zguiGetFontSize(void)
    {
        return ImGui::GetFontSize();
    }

    ZGUI_API void zguiGetFontTexUvWhitePixel(float uv[2])
    {
        const ImVec2 cs = ImGui::GetFontTexUvWhitePixel();
        uv[0] = cs[0];
        uv[1] = cs[1];
    }

    ZGUI_API void zguiPushFont(ImFont *font)
    {
        ImGui::PushFont(font);
    }

    ZGUI_API void zguiPopFont(void)
    {
        ImGui::PopFont();
    }

    ZGUI_API bool zguiTreeNode(const char *label)
    {
        return ImGui::TreeNode(label);
    }

    ZGUI_API bool zguiTreeNodeFlags(const char *label, ImGuiTreeNodeFlags flags)
    {
        return ImGui::TreeNodeEx(label, flags);
    }

    ZGUI_API bool zguiTreeNodeStrId(const char *str_id, const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        const bool ret = ImGui::TreeNodeV(str_id, fmt, args);
        va_end(args);
        return ret;
    }

    ZGUI_API bool zguiTreeNodeStrIdFlags(const char *str_id, ImGuiTreeNodeFlags flags, const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        const bool ret = ImGui::TreeNodeExV(str_id, flags, fmt, args);
        va_end(args);
        return ret;
    }

    ZGUI_API bool zguiTreeNodePtrId(const void *ptr_id, const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        const bool ret = ImGui::TreeNodeV(ptr_id, fmt, args);
        va_end(args);
        return ret;
    }

    ZGUI_API bool zguiTreeNodePtrIdFlags(const void *ptr_id, ImGuiTreeNodeFlags flags, const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        const bool ret = ImGui::TreeNodeExV(ptr_id, flags, fmt, args);
        va_end(args);
        return ret;
    }

    ZGUI_API bool zguiCollapsingHeader(const char *label, ImGuiTreeNodeFlags flags)
    {
        return ImGui::CollapsingHeader(label, flags);
    }

    ZGUI_API bool zguiCollapsingHeaderStatePtr(const char *label, bool *p_visible, ImGuiTreeNodeFlags flags)
    {
        return ImGui::CollapsingHeader(label, p_visible, flags);
    }

    ZGUI_API void zguiSetNextItemOpen(bool is_open, ImGuiCond cond)
    {
        ImGui::SetNextItemOpen(is_open, cond);
    }

    ZGUI_API void zguiTreePushStrId(const char *str_id)
    {
        ImGui::TreePush(str_id);
    }

    ZGUI_API float zguiGetTreeNodeToLabelSpacing() 
    {
        return ImGui::GetTreeNodeToLabelSpacing();
    }

    ZGUI_API void zguiTreePushPtrId(const void *ptr_id)
    {
        ImGui::TreePush(ptr_id);
    }

    ZGUI_API void zguiTreePop(void)
    {
        ImGui::TreePop();
    }

    ZGUI_API void zguiPushStrId(const char *str_id_begin, const char *str_id_end)
    {
        ImGui::PushID(str_id_begin, str_id_end);
    }

    ZGUI_API void zguiPushStrIdZ(const char *str_id)
    {
        ImGui::PushID(str_id);
    }

    ZGUI_API void zguiPushPtrId(const void *ptr_id)
    {
        ImGui::PushID(ptr_id);
    }

    ZGUI_API void zguiPushIntId(int int_id)
    {
        ImGui::PushID(int_id);
    }

    ZGUI_API void zguiPopId(void)
    {
        ImGui::PopID();
    }

    ZGUI_API ImGuiID zguiGetStrId(const char *str_id_begin, const char *str_id_end)
    {
        return ImGui::GetID(str_id_begin, str_id_end);
    }

    ZGUI_API ImGuiID zguiGetStrIdZ(const char *str_id)
    {
        return ImGui::GetID(str_id);
    }

    ZGUI_API ImGuiID zguiGetPtrId(const void *ptr_id)
    {
        return ImGui::GetID(ptr_id);
    }

    ZGUI_API void zguiSetClipboardText(const char *text)
    {
        ImGui::SetClipboardText(text);
    }

    ZGUI_API const char *zguiGetClipboardText(void)
    {
        return ImGui::GetClipboardText();
    }

    ZGUI_API ImFont *zguiIoAddFontDefault(const ImFontConfig *config)
    {
        return ImGui::GetIO().Fonts->AddFontDefault(config);
    }

    ZGUI_API ImFont *zguiIoAddFontFromFileWithConfig(
        const char *filename,
        float size_pixels,
        const ImFontConfig *config,
        const ImWchar *ranges)
    {
        return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, config, ranges);
    }

    ZGUI_API ImFont *zguiIoAddFontFromFile(const char *filename, float size_pixels)
    {
        return ImGui::GetIO().Fonts->AddFontFromFileTTF(filename, size_pixels, nullptr, nullptr);
    }

    ZGUI_API ImFont *zguiIoAddFontFromMemoryWithConfig(
        void *font_data,
        int font_size,
        float size_pixels,
        const ImFontConfig *config,
        const ImWchar *ranges)
    {
        return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(font_data, font_size, size_pixels, config, ranges);
    }

    ZGUI_API ImFont *zguiIoAddFontFromMemory(void *font_data, int font_size, float size_pixels)
    {
        ImFontConfig config = ImFontConfig();
        config.FontDataOwnedByAtlas = false;
        return ImGui::GetIO().Fonts->AddFontFromMemoryTTF(font_data, font_size, size_pixels, &config, nullptr);
    }

    ZGUI_API ImFontConfig zguiFontConfig_Init(void)
    {
        return ImFontConfig();
    }

    ZGUI_API ImFont *zguiIoGetFont(unsigned int index)
    {
        return ImGui::GetIO().Fonts->Fonts[index];
    }

    ZGUI_API void zguiIoSetDefaultFont(ImFont *font)
    {
        ImGui::GetIO().FontDefault = font;
    }

    ZGUI_API unsigned char *zguiIoGetFontsTexDataAsRgba32(int *width, int *height)
    {
        unsigned char *font_pixels;
        int font_width, font_height;
        ImGui::GetIO().Fonts->GetTexDataAsRGBA32(&font_pixels, &font_width, &font_height);
        *width = font_width;
        *height = font_height;
        return font_pixels;
    }

    ZGUI_API void zguiIoSetFontsTexId(ImTextureID id)
    {
        ImGui::GetIO().Fonts->TexID = id;
    }

    ZGUI_API ImTextureID zguiIoGetFontsTexId(void)
    {
        return ImGui::GetIO().Fonts->TexID;
    }

    // Glyph Ranges
    ZGUI_API const ImWchar *zguiIoGetGlyphRangesDefault(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesDefault();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesGreek(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesGreek();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesKorean(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesKorean();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesJapanese(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesJapanese();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesChineseFull(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesChineseFull();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesChineseSimplifiedCommon(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesChineseSimplifiedCommon();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesCyrillic(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesCyrillic();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesThai(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesThai();
    }

    ZGUI_API const ImWchar *zguiIoGetGlyphRangesVietnamese(void)
    {
        return ImGui::GetIO().Fonts->GetGlyphRangesVietnamese();
    }

    ZGUI_API void zguiIoSetConfigWindowsMoveFromTitleBarOnly(bool enabled)
    {
        ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = enabled;
    }

    ZGUI_API bool zguiIoGetWantCaptureMouse(void)
    {
        return ImGui::GetIO().WantCaptureMouse;
    }

    ZGUI_API bool zguiIoGetWantCaptureKeyboard(void)
    {
        return ImGui::GetIO().WantCaptureKeyboard;
    }

    ZGUI_API bool zguiIoGetWantTextInput(void)
    {
        return ImGui::GetIO().WantTextInput;
    }

    ZGUI_API float zguiIoFramerate() {
        return ImGui::GetIO().Framerate;
    }

    ZGUI_API void zguiIoSetIniFilename(const char *filename)
    {
        ImGui::GetIO().IniFilename = filename;
    }

    ZGUI_API void zguiIoSetConfigFlags(ImGuiConfigFlags flags)
    {
        ImGui::GetIO().ConfigFlags = flags;
    }

    ZGUI_API void zguiIoSetDisplaySize(float width, float height)
    {
        ImGui::GetIO().DisplaySize = {width, height};
    }

    ZGUI_API void zguiIoGetDisplaySize(float size[2])
    {
        const ImVec2 ds = ImGui::GetIO().DisplaySize;
        size[0] = ds[0];
        size[1] = ds[1];
    }

    ZGUI_API void zguiIoSetDisplayFramebufferScale(float sx, float sy)
    {
        ImGui::GetIO().DisplayFramebufferScale = {sx, sy};
    }

    ZGUI_API void zguiIoSetDeltaTime(float delta_time)
    {
        ImGui::GetIO().DeltaTime = delta_time;
    }

    ZGUI_API void zguiIoAddFocusEvent(bool focused)
    {
        ImGui::GetIO().AddFocusEvent(focused);
    }

    ZGUI_API void zguiIoAddMousePositionEvent(float x, float y)
    {
        ImGui::GetIO().AddMousePosEvent(x, y);
    }

    ZGUI_API void zguiIoAddMouseButtonEvent(ImGuiMouseButton button, bool down)
    {
        ImGui::GetIO().AddMouseButtonEvent(button, down);
    }

    ZGUI_API void zguiIoAddMouseWheelEvent(float x, float y)
    {
        ImGui::GetIO().AddMouseWheelEvent(x, y);
    }

    ZGUI_API void zguiIoAddKeyEvent(ImGuiKey key, bool down)
    {
        ImGui::GetIO().AddKeyEvent(key, down);
    }

    ZGUI_API void zguiIoAddInputCharactersUTF8(const char *utf8_chars)
    {
        ImGui::GetIO().AddInputCharactersUTF8(utf8_chars);
    }

    ZGUI_API void zguiIoSetKeyEventNativeData(ImGuiKey key, int keycode, int scancode)
    {
        ImGui::GetIO().SetKeyEventNativeData(key, keycode, scancode);
    }

    ZGUI_API void zguiIoAddCharacterEvent(unsigned int c)
    {
        ImGui::GetIO().AddInputCharacter(c);
    }

    ZGUI_API bool zguiIsItemHovered(ImGuiHoveredFlags flags)
    {
        return ImGui::IsItemHovered(flags);
    }

    ZGUI_API bool zguiIsItemActive(void)
    {
        return ImGui::IsItemActive();
    }

    ZGUI_API bool zguiIsItemFocused(void)
    {
        return ImGui::IsItemFocused();
    }

    ZGUI_API bool zguiIsItemClicked(ImGuiMouseButton mouse_button)
    {
        return ImGui::IsItemClicked(mouse_button);
    }

    ZGUI_API bool zguiIsMouseDown(ImGuiMouseButton button)
    {
        return ImGui::IsMouseDown(button);
    }

    ZGUI_API bool zguiIsMouseClicked(ImGuiMouseButton button)
    {
        return ImGui::IsMouseClicked(button);
    }

    ZGUI_API bool zguiIsMouseReleased(ImGuiMouseButton button)
    {
        return ImGui::IsMouseReleased(button);
    }

    ZGUI_API bool zguiIsMouseDoubleClicked(ImGuiMouseButton button)
    {
        return ImGui::IsMouseDoubleClicked(button);
    }

    ZGUI_API int zguiGetMouseClickedCount(ImGuiMouseButton button)
    {
        return ImGui::GetMouseClickedCount(button);
    }

    ZGUI_API bool zguiIsAnyMouseDown() 
    {
        return ImGui::IsAnyMouseDown();
    }

    ZGUI_API bool zguiIsMouseDragging(ImGuiMouseButton button, float lock_threshold)
    {
        return ImGui::IsMouseDragging(button, lock_threshold);
    }

    ZGUI_API bool zguiIsItemVisible(void)
    {
        return ImGui::IsItemVisible();
    }

    ZGUI_API bool zguiIsRectVisible(float pos[2])
    {
        return ImGui::IsRectVisible(ImVec2(pos[0], pos[1]));
    }

    ZGUI_API bool zguiIsItemEdited(void)
    {
        return ImGui::IsItemEdited();
    }

    ZGUI_API bool zguiIsItemActivated(void)
    {
        return ImGui::IsItemActivated();
    }

    ZGUI_API bool zguiIsItemDeactivated(void)
    {
        return ImGui::IsItemDeactivated();
    }

    ZGUI_API bool zguiIsItemDeactivatedAfterEdit(void)
    {
        return ImGui::IsItemDeactivatedAfterEdit();
    }

    ZGUI_API bool zguiIsItemToggledOpen(void)
    {
        return ImGui::IsItemToggledOpen();
    }

    ZGUI_API bool zguiIsAnyItemHovered(void)
    {
        return ImGui::IsAnyItemHovered();
    }

    ZGUI_API bool zguiIsAnyItemActive(void)
    {
        return ImGui::IsAnyItemActive();
    }

    ZGUI_API bool zguiIsAnyItemFocused(void)
    {
        return ImGui::IsAnyItemFocused();
    }

    ZGUI_API void zguiGetContentRegionAvail(float pos[2])
    {
        const ImVec2 p = ImGui::GetContentRegionAvail();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiGetContentRegionMax(float pos[2])
    {
        const ImVec2 p = ImGui::GetContentRegionMax();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiGetWindowContentRegionMin(float pos[2])
    {
        const ImVec2 p = ImGui::GetWindowContentRegionMin();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiGetWindowContentRegionMax(float pos[2])
    {
        const ImVec2 p = ImGui::GetWindowContentRegionMax();
        pos[0] = p.x;
        pos[1] = p.y;
    }

    ZGUI_API void zguiPushTextWrapPos(float wrap_pos_x)
    {
        ImGui::PushTextWrapPos(wrap_pos_x);
    }

    ZGUI_API void zguiPopTextWrapPos(void)
    {
        ImGui::PopTextWrapPos();
    }

    ZGUI_API bool zguiBeginTabBar(const char *string, ImGuiTabBarFlags flags)
    {
        return ImGui::BeginTabBar(string, flags);
    }

    ZGUI_API bool zguiBeginTabItem(const char *string, bool *p_open, ImGuiTabItemFlags flags)
    {
        return ImGui::BeginTabItem(string, p_open, flags);
    }

    ZGUI_API void zguiEndTabItem(void)
    {
        ImGui::EndTabItem();
    }

    ZGUI_API void zguiEndTabBar(void)
    {
        ImGui::EndTabBar();
    }

    ZGUI_API bool zguiTabItemButton(const char* label, ImGuiTabItemFlags flags ) 
    {
        return ImGui::TabItemButton(label, flags);
    }

    ZGUI_API void zguiSetTabItemClosed(const char *tab_or_docked_window_label)
    {
        ImGui::SetTabItemClosed(tab_or_docked_window_label);
    }

    ZGUI_API bool zguiBeginMenuBar(void)
    {
        return ImGui::BeginMenuBar();
    }

    ZGUI_API void zguiEndMenuBar(void)
    {
        ImGui::EndMenuBar();
    }

    ZGUI_API bool zguiBeginMainMenuBar(void)
    {
        return ImGui::BeginMainMenuBar();
    }

    ZGUI_API void zguiEndMainMenuBar(void)
    {
        ImGui::EndMainMenuBar();
    }

    ZGUI_API bool zguiBeginMenu(const char *label, bool enabled)
    {
        return ImGui::BeginMenu(label, enabled);
    }

    ZGUI_API void zguiEndMenu(void)
    {
        ImGui::EndMenu();
    }

    ZGUI_API bool zguiMenuItem(const char *label, const char *shortcut, bool selected, bool enabled)
    {
        return ImGui::MenuItem(label, shortcut, selected, enabled);
    }

    ZGUI_API bool zguiMenuItemPtr(const char *label, const char *shortcut, bool *selected, bool enabled)
    {
        return ImGui::MenuItem(label, shortcut, selected, enabled);
    }

    ZGUI_API bool zguiBeginTooltip(void)
    {
        return ImGui::BeginTooltip();
    }

    ZGUI_API void zguiEndTooltip(void)
    {
        ImGui::EndTooltip();
    }

    ZGUI_API bool zguiBeginPopup(const char *str_id, ImGuiWindowFlags flags)
    {
        return ImGui::BeginPopup(str_id, flags);
    }

    ZGUI_API bool zguiBeginPopupContextWindow(void)
    {
        return ImGui::BeginPopupContextWindow();
    }

    ZGUI_API bool zguiBeginPopupContextItem(void)
    {
        return ImGui::BeginPopupContextItem();
    }

    ZGUI_API bool zguiBeginPopupModal(const char *name, bool *p_open, ImGuiWindowFlags flags)
    {
        return ImGui::BeginPopupModal(name, p_open, flags);
    }

    ZGUI_API void zguiEndPopup(void)
    {
        ImGui::EndPopup();
    }

    ZGUI_API void zguiOpenPopup(const char *str_id, ImGuiPopupFlags popup_flags)
    {
        ImGui::OpenPopup(str_id, popup_flags);
    }

    ZGUI_API void zguiIsPopupOpen(const char *str_id, ImGuiPopupFlags popup_flags)
    {
        ImGui::IsPopupOpen(str_id, popup_flags);
    }

    ZGUI_API void zguiCloseCurrentPopup(void)
    {
        ImGui::CloseCurrentPopup();
    }

    ZGUI_API void zguiPlotLines(
        const char* label, 
        const float* values, 
        int values_count, 
        int values_offset, 
        const char* overlay_text, 
        float scale_min, 
        float scale_max, 
        float graph_size[2], 
        int stride)
    {
        ImGui::PlotLines(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, ImVec2(graph_size[0], graph_size[1]), stride);
    }  
    

    ZGUI_API void zguiPlotHistogram(
        const char* label, 
        const float* values, 
        int values_count, 
        int values_offset, 
        const char* overlay_text, 
        float scale_min, 
        float scale_max, 
        float graph_size[2], 
        int stride)
    {
        ImGui::PlotHistogram(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, ImVec2(graph_size[0], graph_size[1]), stride);
    }

    //--------------------------------------------------------------------------------------------------
    //
    // Tables
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API bool zguiBeginTable(
        const char *str_id,
        int column,
        ImGuiTableFlags flags,
        const float outer_size[2],
        float inner_width)
    {
        return ImGui::BeginTable(str_id, column, flags, {outer_size[0], outer_size[1]}, inner_width);
    }

    ZGUI_API void zguiEndTable(void)
    {
        ImGui::EndTable();
    }

    ZGUI_API void zguiTableNextRow(ImGuiTableRowFlags row_flags, float min_row_height)
    {
        ImGui::TableNextRow(row_flags, min_row_height);
    }

    ZGUI_API bool zguiTableNextColumn(void)
    {
        return ImGui::TableNextColumn();
    }

    ZGUI_API bool zguiTableSetColumnIndex(int column_n)
    {
        return ImGui::TableSetColumnIndex(column_n);
    }

    ZGUI_API void zguiTableSetupColumn(
        const char *label,
        ImGuiTableColumnFlags flags,
        float init_width_or_height,
        ImGuiID user_id)
    {
        ImGui::TableSetupColumn(label, flags, init_width_or_height, user_id);
    }

    ZGUI_API void zguiTableSetupScrollFreeze(int cols, int rows)
    {
        ImGui::TableSetupScrollFreeze(cols, rows);
    }

    ZGUI_API void zguiTableHeadersRow(void)
    {
        ImGui::TableHeadersRow();
    }

    ZGUI_API void zguiTableHeader(const char *label)
    {
        ImGui::TableHeader(label);
    }

    ZGUI_API ImGuiTableSortSpecs *zguiTableGetSortSpecs(void)
    {
        return ImGui::TableGetSortSpecs();
    }

    ZGUI_API int zguiTableGetColumnCount(void)
    {
        return ImGui::TableGetColumnCount();
    }

    ZGUI_API int zguiTableGetColumnIndex(void)
    {
        return ImGui::TableGetColumnIndex();
    }

    ZGUI_API int zguiTableGetRowIndex(void)
    {
        return ImGui::TableGetRowIndex();
    }

    ZGUI_API const char *zguiTableGetColumnName(int column_n)
    {
        return ImGui::TableGetColumnName(column_n);
    }

    ZGUI_API ImGuiTableColumnFlags zguiTableGetColumnFlags(int column_n)
    {
        return ImGui::TableGetColumnFlags(column_n);
    }

    ZGUI_API void zguiTableSetColumnEnabled(int column_n, bool v)
    {
        ImGui::TableSetColumnEnabled(column_n, v);
    }

    ZGUI_API int zguiTableGetHoveredColumn() 
    {
        return ImGui::TableGetHoveredColumn();
    }

    ZGUI_API void zguiTableSetBgColor(ImGuiTableBgTarget target, ImU32 color, int column_n)
    {
        ImGui::TableSetBgColor(target, color, column_n);
    }

    ZGUI_API void zguiColumns(int count , const char* id , bool borders)
    {
        ImGui::Columns();
    }

    ZGUI_API void zguiNextColumn()
    {
        ImGui::NextColumn();
    }

    ZGUI_API int zguiGetColumnIndex()
    {
        return ImGui::GetColumnIndex();
    }

    ZGUI_API float zguiGetColumnWidth(int column_index) //-1
    {
        return ImGui::GetColumnWidth(column_index);
    }

    ZGUI_API void zguiSetColumnWidth(int column_index, float width)
    {
        ImGui::SetColumnWidth(column_index, width);
    }

    ZGUI_API float zguiGetColumnOffset(int column_index ) //-1
    {
        return ImGui::GetColumnOffset(column_index);
    }

    ZGUI_API void zguiSetColumnOffset(int column_index, float offset_x)
    {
        ImGui::SetColumnOffset(column_index, offset_x);
    }

    ZGUI_API int zguiGetColumnsCount()
    {
        return ImGui::GetColumnsCount();
    }

    //--------------------------------------------------------------------------------------------------
    //
    // Color Utilities
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API void zguiColorConvertU32ToFloat4(ImU32 in, float rgba[4])
    {
        const ImVec4 c = ImGui::ColorConvertU32ToFloat4(in);
        rgba[0] = c.x;
        rgba[1] = c.y;
        rgba[2] = c.z;
        rgba[3] = c.w;
    }

    ZGUI_API ImU32 zguiColorConvertFloat4ToU32(const float in[4])
    {
        return ImGui::ColorConvertFloat4ToU32({in[0], in[1], in[2], in[3]});
    }

    ZGUI_API void zguiColorConvertRGBtoHSV(float r, float g, float b, float *out_h, float *out_s, float *out_v)
    {
        return ImGui::ColorConvertRGBtoHSV(r, g, b, *out_h, *out_s, *out_v);
    }

    ZGUI_API void zguiColorConvertHSVtoRGB(float h, float s, float v, float *out_r, float *out_g, float *out_b)
    {
        return ImGui::ColorConvertHSVtoRGB(h, s, v, *out_r, *out_g, *out_b);
    }
    //--------------------------------------------------------------------------------------------------
    //
    // Inputs Utilities: Keyboard
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API bool zguiIsKeyDown(ImGuiKey key)
    {
        return ImGui::IsKeyDown(key);
    }

    ZGUI_API bool zguiIsKeyPressed(ImGuiKey key, bool repeat)
    {
        return ImGui::IsKeyPressed(key, repeat);
    }

    ZGUI_API bool zguiIsKeyReleased(ImGuiKey key)
    {
        return ImGui::IsKeyReleased(key);
    }

    ZGUI_API void zguiSetNextFrameWantCaptureKeyboard(bool want_capture_keyboard) 
    {
        ImGui::SetNextFrameWantCaptureKeyboard(want_capture_keyboard);
    }

    ZGUI_API int zguiGetKeyPressedAmount(ImGuiKey key, float repeat_delay, float rate) 
    {
        return ImGui::GetKeyPressedAmount(key, repeat_delay, rate);
    }

    ZGUI_API void zguiSetItemKeyOwner(ImGuiKey key) 
    {
        ImGui::SetItemKeyOwner(key);
    }
    //--------------------------------------------------------------------------------------------------
    //
    // DrawList
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API ImDrawList *zguiGetWindowDrawList(void)
    {
        return ImGui::GetWindowDrawList();
    }

    ZGUI_API float zguiGetWindowDpiScale(void)
    {
        return ImGui::GetWindowDpiScale();
    }

    ZGUI_API ImDrawList *zguiGetBackgroundDrawList(void)
    {
        return ImGui::GetBackgroundDrawList();
    }

    ZGUI_API ImDrawList *zguiGetForegroundDrawList(void)
    {
        return ImGui::GetForegroundDrawList();
    }

    ZGUI_API ImDrawList *zguiCreateDrawList(void)
    {
        return IM_NEW(ImDrawList)(ImGui::GetDrawListSharedData());
    }

    ZGUI_API void zguiDestroyDrawList(ImDrawList *draw_list)
    {
        IM_DELETE(draw_list);
    }

    ZGUI_API const char *zguiDrawList_GetOwnerName(ImDrawList *draw_list)
    {
        return draw_list->_OwnerName;
    }

    ZGUI_API void zguiDrawList_ResetForNewFrame(ImDrawList *draw_list)
    {
        draw_list->_ResetForNewFrame();
    }

    ZGUI_API void zguiDrawList_ClearFreeMemory(ImDrawList *draw_list)
    {
        draw_list->_ClearFreeMemory();
    }

    ZGUI_API int zguiDrawList_GetVertexBufferLength(ImDrawList *draw_list)
    {
        return draw_list->VtxBuffer.size();
    }
    ZGUI_API ImDrawVert *zguiDrawList_GetVertexBufferData(ImDrawList *draw_list)
    {
        return draw_list->VtxBuffer.begin();
    }

    ZGUI_API int zguiDrawList_GetIndexBufferLength(ImDrawList *draw_list)
    {
        return draw_list->IdxBuffer.size();
    }
    ZGUI_API ImDrawIdx *zguiDrawList_GetIndexBufferData(ImDrawList *draw_list)
    {
        return draw_list->IdxBuffer.begin();
    }
    ZGUI_API unsigned int zguiDrawList_GetCurrentIndex(ImDrawList *draw_list)
    {
        return draw_list->_VtxCurrentIdx;
    }

    ZGUI_API int zguiDrawList_GetCmdBufferLength(ImDrawList *draw_list)
    {
        return draw_list->CmdBuffer.size();
    }
    ZGUI_API ImDrawCmd *zguiDrawList_GetCmdBufferData(ImDrawList *draw_list)
    {
        return draw_list->CmdBuffer.begin();
    }

    ZGUI_API void zguiDrawList_SetFlags(ImDrawList *draw_list, ImDrawListFlags flags)
    {
        draw_list->Flags = flags;
    }
    ZGUI_API ImDrawListFlags zguiDrawList_GetFlags(ImDrawList *draw_list)
    {
        return draw_list->Flags;
    }

    ZGUI_API void zguiDrawList_PushClipRect(
        ImDrawList *draw_list,
        const float clip_rect_min[2],
        const float clip_rect_max[2],
        bool intersect_with_current_clip_rect)
    {
        draw_list->PushClipRect(
            {clip_rect_min[0], clip_rect_min[1]},
            {clip_rect_max[0], clip_rect_max[1]},
            intersect_with_current_clip_rect);
    }

    ZGUI_API void zguiDrawList_PushClipRectFullScreen(ImDrawList *draw_list)
    {
        draw_list->PushClipRectFullScreen();
    }

    ZGUI_API void zguiDrawList_PopClipRect(ImDrawList *draw_list)
    {
        draw_list->PopClipRect();
    }

    ZGUI_API void zguiDrawList_PushTextureId(ImDrawList *draw_list, ImTextureID texture_id)
    {
        draw_list->PushTextureID(texture_id);
    }

    ZGUI_API void zguiDrawList_PopTextureId(ImDrawList *draw_list)
    {
        draw_list->PopTextureID();
    }

    ZGUI_API void zguiDrawList_GetClipRectMin(ImDrawList *draw_list, float clip_min[2])
    {
        const ImVec2 c = draw_list->GetClipRectMin();
        clip_min[0] = c.x;
        clip_min[1] = c.y;
    }

    ZGUI_API void zguiDrawList_GetClipRectMax(ImDrawList *draw_list, float clip_max[2])
    {
        const ImVec2 c = draw_list->GetClipRectMax();
        clip_max[0] = c.x;
        clip_max[1] = c.y;
    }

    ZGUI_API void zguiDrawList_AddLine(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        ImU32 col,
        float thickness)
    {
        draw_list->AddLine({p1[0], p1[1]}, {p2[0], p2[1]}, col, thickness);
    }

    ZGUI_API void zguiDrawList_AddRect(
        ImDrawList *draw_list,
        const float pmin[2],
        const float pmax[2],
        ImU32 col,
        float rounding,
        ImDrawFlags flags,
        float thickness)
    {
        draw_list->AddRect({pmin[0], pmin[1]}, {pmax[0], pmax[1]}, col, rounding, flags, thickness);
    }

    ZGUI_API void zguiDrawList_AddRectFilled(
        ImDrawList *draw_list,
        const float pmin[2],
        const float pmax[2],
        ImU32 col,
        float rounding,
        ImDrawFlags flags)
    {
        draw_list->AddRectFilled({pmin[0], pmin[1]}, {pmax[0], pmax[1]}, col, rounding, flags);
    }

    ZGUI_API void zguiDrawList_AddRectFilledMultiColor(
        ImDrawList *draw_list,
        const float pmin[2],
        const float pmax[2],
        ImU32 col_upr_left,
        ImU32 col_upr_right,
        ImU32 col_bot_right,
        ImU32 col_bot_left)
    {
        draw_list->AddRectFilledMultiColor(
            {pmin[0], pmin[1]},
            {pmax[0], pmax[1]},
            col_upr_left,
            col_upr_right,
            col_bot_right,
            col_bot_left);
    }

    ZGUI_API void zguiDrawList_AddQuad(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        const float p4[2],
        ImU32 col,
        float thickness)
    {
        draw_list->AddQuad({p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}, col, thickness);
    }

    ZGUI_API void zguiDrawList_AddQuadFilled(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        const float p4[2],
        ImU32 col)
    {
        draw_list->AddQuadFilled({p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}, col);
    }

    ZGUI_API void zguiDrawList_AddTriangle(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        ImU32 col,
        float thickness)
    {
        draw_list->AddTriangle({p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, col, thickness);
    }

    ZGUI_API void zguiDrawList_AddTriangleFilled(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        ImU32 col)
    {
        draw_list->AddTriangleFilled({p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, col);
    }

    ZGUI_API void zguiDrawList_AddCircle(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        ImU32 col,
        int num_segments,
        float thickness)
    {
        draw_list->AddCircle({center[0], center[1]}, radius, col, num_segments, thickness);
    }

    ZGUI_API void zguiDrawList_AddCircleFilled(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        ImU32 col,
        int num_segments)
    {
        draw_list->AddCircleFilled({center[0], center[1]}, radius, col, num_segments);
    }

    ZGUI_API void zguiDrawList_AddEllipse(
        ImDrawList *draw_list,
        const float center[2],
        const float radius[2],
        ImU32 col,
		float rot,
        int num_segments,
        float thickness)
    {
        draw_list->AddEllipse({center[0], center[1]}, {radius[0], radius[1]}, col, rot, num_segments, thickness);
    }

    ZGUI_API void zguiDrawList_AddEllipseFilled(
        ImDrawList *draw_list,
        const float center[2],
        const float radius[2],
        ImU32 col,
		float rot,
        int num_segments)
    {
        draw_list->AddEllipseFilled({center[0], center[1]}, {radius[0], radius[1]}, col, rot, num_segments);
    }

    ZGUI_API void zguiDrawList_AddNgon(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        ImU32 col,
        int num_segments,
        float thickness)
    {
        draw_list->AddNgon({center[0], center[1]}, radius, col, num_segments, thickness);
    }

    ZGUI_API void zguiDrawList_AddNgonFilled(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        ImU32 col,
        int num_segments)
    {
        draw_list->AddNgonFilled({center[0], center[1]}, radius, col, num_segments);
    }

    ZGUI_API void zguiDrawList_AddText(
        ImDrawList *draw_list,
        const float pos[2],
        ImU32 col,
        const char *text_begin,
        const char *text_end)
    {
        draw_list->AddText({pos[0], pos[1]}, col, text_begin, text_end);
    }

    ZGUI_API void zguiDrawList_AddTextExtended(
        ImDrawList *draw_list,
        ImFont* font, 
        float font_size, 
        const float pos[2], 
        ImU32 col, 
        const char* text_begin, 
        const char* text_end, 
        float wrap_width, 
        const float cpu_fine_clip_rect[][4])
    {   
        const ImVec4* clip_rect = (cpu_fine_clip_rect != nullptr) ? (const ImVec4 *)&cpu_fine_clip_rect[0][0] : nullptr;
        draw_list->AddText(font, font_size, {pos[0], pos[1]}, col, text_begin, text_end, wrap_width, clip_rect);
    }

    ZGUI_API void zguiDrawList_AddPolyline(
        ImDrawList *draw_list,
        const float points[][2],
        int num_points,
        ImU32 col,
        ImDrawFlags flags,
        float thickness)
    {
        draw_list->AddPolyline((const ImVec2 *)&points[0][0], num_points, col, flags, thickness);
    }

    ZGUI_API void zguiDrawList_AddConvexPolyFilled(
        ImDrawList *draw_list,
        const float points[][2],
        int num_points,
        ImU32 col)
    {
        draw_list->AddConvexPolyFilled((const ImVec2 *)&points[0][0], num_points, col);
    }

    ZGUI_API void zguiDrawList_AddConcavePolyFilled(
        ImDrawList *draw_list,
        const float points[][2],
        int num_points,
        ImU32 col)
    {
        draw_list->AddConcavePolyFilled((const ImVec2 *)&points[0][0], num_points, col);
    }

    ZGUI_API void zguiDrawList_AddBezierCubic(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        const float p4[2],
        ImU32 col,
        float thickness,
        int num_segments)
    {
        draw_list->AddBezierCubic(
            {p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}, col, thickness, num_segments);
    }

    ZGUI_API void zguiDrawList_AddBezierQuadratic(
        ImDrawList *draw_list,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        ImU32 col,
        float thickness,
        int num_segments)
    {
        draw_list->AddBezierQuadratic(
            {p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, col, thickness, num_segments);
    }

    ZGUI_API void zguiDrawList_AddImage(
        ImDrawList *draw_list,
        ImTextureID user_texture_id,
        const float pmin[2],
        const float pmax[2],
        const float uvmin[2],
        const float uvmax[2],
        ImU32 col)
    {
        draw_list->AddImage(
            user_texture_id,
            {pmin[0], pmin[1]},
            {pmax[0], pmax[1]},
            {uvmin[0], uvmin[1]},
            {uvmax[0], uvmax[1]},
            col);
    }

    ZGUI_API void zguiDrawList_AddImageQuad(
        ImDrawList *draw_list,
        ImTextureID user_texture_id,
        const float p1[2],
        const float p2[2],
        const float p3[2],
        const float p4[2],
        const float uv1[2],
        const float uv2[2],
        const float uv3[2],
        const float uv4[2],
        ImU32 col)
    {
        draw_list->AddImageQuad(
            user_texture_id,
            {p1[0], p1[1]},
            {p2[0], p2[1]},
            {p3[0], p3[1]},
            {p4[0], p4[1]},
            {uv1[0], uv1[1]},
            {uv2[0], uv2[1]},
            {uv3[0], uv3[1]},
            {uv4[0], uv4[1]},
            col);
    }

    ZGUI_API void zguiDrawList_AddImageRounded(
        ImDrawList *draw_list,
        ImTextureID user_texture_id,
        const float pmin[2],
        const float pmax[2],
        const float uvmin[2],
        const float uvmax[2],
        ImU32 col,
        float rounding,
        ImDrawFlags flags)
    {
        draw_list->AddImageRounded(
            user_texture_id,
            {pmin[0], pmin[1]},
            {pmax[0], pmax[1]},
            {uvmin[0], uvmin[1]},
            {uvmax[0], uvmax[1]},
            col,
            rounding,
            flags);
    }

    ZGUI_API void zguiDrawList_PathClear(ImDrawList *draw_list)
    {
        draw_list->PathClear();
    }

    ZGUI_API void zguiDrawList_PathLineTo(ImDrawList *draw_list, const float pos[2])
    {
        draw_list->PathLineTo({pos[0], pos[1]});
    }

    ZGUI_API void zguiDrawList_PathLineToMergeDuplicate(ImDrawList *draw_list, const float pos[2])
    {
        draw_list->PathLineToMergeDuplicate({pos[0], pos[1]});
    }

    ZGUI_API void zguiDrawList_PathFillConvex(ImDrawList *draw_list, ImU32 col)
    {
        draw_list->PathFillConvex(col);
    }

    ZGUI_API void zguiDrawList_PathFillConcave(ImDrawList *draw_list, ImU32 col)
    {
        draw_list->PathFillConcave(col);
    }

    ZGUI_API void zguiDrawList_PathStroke(ImDrawList *draw_list, ImU32 col, ImDrawFlags flags, float thickness)
    {
        draw_list->PathStroke(col, flags, thickness);
    }

    ZGUI_API void zguiDrawList_PathArcTo(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        float a_min,
        float a_max,
        int num_segments)
    {
        draw_list->PathArcTo({center[0], center[1]}, radius, a_min, a_max, num_segments);
    }

    ZGUI_API void zguiDrawList_PathArcToFast(
        ImDrawList *draw_list,
        const float center[2],
        float radius,
        int a_min_of_12,
        int a_max_of_12)
    {
        draw_list->PathArcToFast({center[0], center[1]}, radius, a_min_of_12, a_max_of_12);
    }

    ZGUI_API void zguiDrawList_PathEllipticalArcTo(
        ImDrawList *draw_list,
        const float center[2],
        const float radius[2],
		float rot,
        int a_min,
        int a_max,
        int num_segments)
    {
        draw_list->PathEllipticalArcTo({center[0], center[1]}, {radius[0], radius[1]}, rot, a_min, a_max, num_segments);
    }

    ZGUI_API void zguiDrawList_PathBezierCubicCurveTo(
        ImDrawList *draw_list,
        const float p2[2],
        const float p3[2],
        const float p4[2],
        int num_segments)
    {
        draw_list->PathBezierCubicCurveTo({p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}, num_segments);
    }

    ZGUI_API void zguiDrawList_PathBezierQuadraticCurveTo(
        ImDrawList *draw_list,
        const float p2[2],
        const float p3[2],
        int num_segments)
    {
        draw_list->PathBezierQuadraticCurveTo({p2[0], p2[1]}, {p3[0], p3[1]}, num_segments);
    }

    ZGUI_API void zguiDrawList_PathRect(
        ImDrawList *draw_list,
        const float rect_min[2],
        const float rect_max[2],
        float rounding,
        ImDrawFlags flags)
    {
        draw_list->PathRect({rect_min[0], rect_min[1]}, {rect_max[0], rect_max[1]}, rounding, flags);
    }

    ZGUI_API void zguiDrawList_PrimReserve(ImDrawList *draw_list, int idx_count, int vtx_count)
    {
        draw_list->PrimReserve(idx_count, vtx_count);
    }

    ZGUI_API void zguiDrawList_PrimUnreserve(ImDrawList *draw_list, int idx_count, int vtx_count)
    {
        draw_list->PrimUnreserve(idx_count, vtx_count);
    }

    ZGUI_API void zguiDrawList_PrimRect(
        ImDrawList *draw_list,
        const float a[2],
        const float b[2],
        ImU32 col)
    {
        draw_list->PrimRect({a[0], a[1]}, {b[0], b[1]}, col);
    }

    ZGUI_API void zguiDrawList_PrimRectUV(
        ImDrawList *draw_list,
        const float a[2],
        const float b[2],
        const float uv_a[2],
        const float uv_b[2],
        ImU32 col)
    {
        draw_list->PrimRectUV({a[0], a[1]}, {b[0], b[1]}, {uv_a[0], uv_a[1]}, {uv_b[0], uv_b[1]}, col);
    }

    ZGUI_API void zguiDrawList_PrimQuadUV(
        ImDrawList *draw_list,
        const float a[2],
        const float b[2],
        const float c[2],
        const float d[2],
        const float uv_a[2],
        const float uv_b[2],
        const float uv_c[2],
        const float uv_d[2],
        ImU32 col)
    {
        draw_list->PrimQuadUV(
            {a[0], a[1]}, {b[0], b[1]}, {c[0], c[1]}, {d[0], d[1]},
            {uv_a[0], uv_a[1]}, {uv_b[0], uv_b[1]}, {uv_c[0], uv_c[1]}, {uv_d[0], uv_d[1]},
            col);
    }

    ZGUI_API void zguiDrawList_PrimWriteVtx(
        ImDrawList *draw_list,
        const float pos[2],
        const float uv[2],
        ImU32 col)
    {
        draw_list->PrimWriteVtx({pos[0], pos[1]}, {uv[0], uv[1]}, col);
    }

    ZGUI_API void zguiDrawList_PrimWriteIdx(ImDrawList *draw_list, ImDrawIdx idx)
    {
        draw_list->PrimWriteIdx(idx);
    }

    ZGUI_API void zguiDrawList_AddCallback(ImDrawList *draw_list, ImDrawCallback callback, void *callback_data)
    {
        draw_list->AddCallback(callback, callback_data);
    }

    ZGUI_API void zguiDrawList_AddResetRenderStateCallback(ImDrawList *draw_list)
    {
        draw_list->AddCallback(ImDrawCallback_ResetRenderState, NULL);
    }
    //--------------------------------------------------------------------------------------------------
    //
    // Viewport
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API ImGuiViewport *zguiGetMainViewport(void)
    {
        return ImGui::GetMainViewport();
    }

    ZGUI_API ImGuiID zguiViewport_GetId(ImGuiViewport *viewport)
    {
        return viewport->ID;
    }

    ZGUI_API void zguiViewport_GetPos(ImGuiViewport *viewport, float p[2])
    {
        const ImVec2 pos = viewport->Pos;
        p[0] = pos.x;
        p[1] = pos.y;
    }

    ZGUI_API void zguiViewport_GetSize(ImGuiViewport *viewport, float p[2])
    {
        const ImVec2 sz = viewport->Size;
        p[0] = sz.x;
        p[1] = sz.y;
    }

    ZGUI_API void zguiViewport_GetWorkPos(ImGuiViewport *viewport, float p[2])
    {
        const ImVec2 pos = viewport->WorkPos;
        p[0] = pos.x;
        p[1] = pos.y;
    }

    ZGUI_API void zguiViewport_GetWorkSize(ImGuiViewport *viewport, float p[2])
    {
        const ImVec2 sz = viewport->WorkSize;
        p[0] = sz.x;
        p[1] = sz.y;
    }

    ZGUI_API void zguiUpdatePlatformWindows() {
        ImGui::UpdatePlatformWindows();
    }

    ZGUI_API void zguiRenderPlatformWindowsDefault() {
        ImGui::RenderPlatformWindowsDefault();
    }

    //--------------------------------------------------------------------------------------------------
    //
    // Docking
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API ImGuiID zguiDockSpace(const char *str_id, float size[2], ImGuiDockNodeFlags flags)
    {
        return ImGui::DockSpace(ImGui::GetID(str_id), {size[0], size[1]}, flags);
    }

    ZGUI_API ImGuiID zguiDockSpaceOverViewport(ImGuiID dockspace_id, const ImGuiViewport *viewport, ImGuiDockNodeFlags dockspace_flags)
    {
        return ImGui::DockSpaceOverViewport(dockspace_id, viewport, dockspace_flags);
    }

    //--------------------------------------------------------------------------------------------------
    //
    // DockBuilder (Unstable internal imgui API, subject to change, use at own risk)
    //
    //--------------------------------------------------------------------------------------------------
    ZGUI_API void zguiDockNodeRect(const ImGuiDockNode* node, ImRect* out_rect)
    {
        *out_rect = node->Rect();
    }

    ZGUI_API void zguiDockBuilderDockWindow(const char *window_name, ImGuiID node_id)
    {
        ImGui::DockBuilderDockWindow(window_name, node_id);
    }

    ZGUI_API ImGuiDockNode* zguiDockBuilderGetNode(ImGuiID node_id)
    {
        return ImGui::DockBuilderGetNode(node_id);
    }

    ZGUI_API ImGuiDockNode* zguiDockBuilderGetCentralNode(ImGuiID node_id)
    {
        return ImGui::DockBuilderGetCentralNode(node_id);
    }

    ZGUI_API ImGuiID zguiDockBuilderAddNode(ImGuiID node_id, ImGuiDockNodeFlags flags)
    {
        return ImGui::DockBuilderAddNode(node_id, flags);
    }

    ZGUI_API void zguiDockBuilderRemoveNode(ImGuiID node_id)
    {
        ImGui::DockBuilderRemoveNode(node_id);
    }

    ZGUI_API void zguiDockBuilderSetNodePos(ImGuiID node_id, float pos[2])
    {
        ImGui::DockBuilderSetNodePos(node_id, {pos[0], pos[1]});
    }

    ZGUI_API void zguiDockBuilderSetNodeSize(ImGuiID node_id, float size[2])
    {
        ImGui::DockBuilderSetNodeSize(node_id, {size[0], size[1]});
    }

    ZGUI_API ImGuiID zguiDockBuilderSplitNode(
        ImGuiID node_id,
        ImGuiDir split_dir,
        float size_ratio_for_node_at_dir,
        ImGuiID *out_id_at_dir,
        ImGuiID *out_id_at_opposite_dir)
    {
        return ImGui::DockBuilderSplitNode(
            node_id,
            split_dir,
            size_ratio_for_node_at_dir,
            out_id_at_dir,
            out_id_at_opposite_dir);
    }

    ZGUI_API void zguiDockBuilderFinish(ImGuiID node_id)
    {
        ImGui::DockBuilderFinish(node_id);
    }
} /* extern "C" */
