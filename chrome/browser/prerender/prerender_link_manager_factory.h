// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_PRERENDER_PRERENDER_LINK_MANAGER_FACTORY_H_
#define CHROME_BROWSER_PRERENDER_PRERENDER_LINK_MANAGER_FACTORY_H_

#include "base/compiler_specific.h"
#include "base/memory/singleton.h"
#include "components/browser_context_keyed_service/browser_context_keyed_service_factory.h"

class Profile;

namespace prerender {

class PrerenderLinkManager;

class PrerenderLinkManagerFactory : public BrowserContextKeyedServiceFactory {
 public:
  static PrerenderLinkManager* GetForProfile(Profile* profile);
  static PrerenderLinkManagerFactory* GetInstance();

 private:
  friend struct DefaultSingletonTraits<PrerenderLinkManagerFactory>;

  PrerenderLinkManagerFactory();
  virtual ~PrerenderLinkManagerFactory() { }

  virtual BrowserContextKeyedService* BuildServiceInstanceFor(
      content::BrowserContext* profile) const OVERRIDE;
  virtual content::BrowserContext* GetBrowserContextToUse(
      content::BrowserContext* context) const OVERRIDE;
};

}  // namespace prerender

#endif  // CHROME_BROWSER_PRERENDER_PRERENDER_LINK_MANAGER_FACTORY_H_
