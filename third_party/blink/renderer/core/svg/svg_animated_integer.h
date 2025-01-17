/*
 * Copyright (C) 2014 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SVG_SVG_ANIMATED_INTEGER_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SVG_SVG_ANIMATED_INTEGER_H_

#include "third_party/blink/renderer/core/svg/properties/svg_animated_property.h"
#include "third_party/blink/renderer/core/svg/svg_integer.h"
#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/heap/heap.h"

namespace blink {

class SVGAnimatedIntegerOptionalInteger;

// SVG Spec: http://www.w3.org/TR/SVG11/types.html#InterfaceSVGAnimatedInteger
class SVGAnimatedInteger : public ScriptWrappable,
                           public SVGAnimatedProperty<SVGInteger> {
  DEFINE_WRAPPERTYPEINFO();
  USING_GARBAGE_COLLECTED_MIXIN(SVGAnimatedInteger);

 public:
  static SVGAnimatedInteger* Create(SVGElement* context_element,
                                    const QualifiedName& attribute_name,
                                    int initial) {
    SVGInteger* initial_value = SVGInteger::Create(initial);
    return MakeGarbageCollected<SVGAnimatedInteger>(
        context_element, attribute_name, initial_value);
  }
  static SVGAnimatedInteger* Create(SVGElement* context_element,
                                    const QualifiedName& attribute_name,
                                    SVGInteger* initial_value) {
    return MakeGarbageCollected<SVGAnimatedInteger>(
        context_element, attribute_name, initial_value);
  }

  SVGAnimatedInteger(SVGElement* context_element,
                     const QualifiedName& attribute_name,
                     int initial)
      : SVGAnimatedInteger(context_element,
                           attribute_name,
                           MakeGarbageCollected<SVGInteger>(initial)) {}

  SVGAnimatedInteger(SVGElement* context_element,
                     const QualifiedName& attribute_name,
                     SVGInteger* initial_value)
      : SVGAnimatedProperty<SVGInteger>(context_element,
                                        attribute_name,
                                        initial_value,
                                        CSSPropertyID::kInvalid,
                                        initial_value->Value()),
        parent_integer_optional_integer_(nullptr) {}

  void SynchronizeAttribute() override;

  void SetParentOptionalInteger(
      SVGAnimatedIntegerOptionalInteger* number_optional_integer) {
    parent_integer_optional_integer_ = number_optional_integer;
  }

  void Trace(blink::Visitor*) override;

 protected:
  Member<SVGAnimatedIntegerOptionalInteger> parent_integer_optional_integer_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_SVG_SVG_ANIMATED_INTEGER_H_
